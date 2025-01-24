#ifdef TEST_APP
#include "FreeRTOS.h"
#include "task.h"

#include "app_tasks.h"
#include "pwr.h"
#include "qrcode/qrscan.h"
#include "screen/screen.h"
#include "ui/dialog.h"
#include "ui/settings_ui.h"
#include "ui/theme.h"
#include "ui/ui_internal.h"

struct ui_cmd g_ui_cmd;
struct ui_ctx g_ui_ctx;

#define TH_KEYPAD_FIELD_HEIGHT 30
#define TH_KEYPAD_FIELD_WIDTH 30
#define TH_KEYPAD_FIELD_MARGIN TH_DEF_LEFT_MARGIN
#define TH_KEYPAD_FIELD_VERTICAL_MARGIN 16

#define TH_FIELD_MARGIN ((SCREEN_WIDTH - ((TH_KEYPAD_FIELD_WIDTH * 3) + (TH_KEYPAD_FIELD_MARGIN * 2))) / 2)

#define COLOR_TEST_HEADER_REFRESH_MS (1 * 60 * 1000)

static app_err_t test_keypad() {
  g_ui_ctx.battery = pwr_battery_level();
  dialog_title("Keypad test");
  dialog_footer(TH_TITLE_HEIGHT);

  screen_area_t area = {
      .x = TH_FIELD_MARGIN,
      .y = TH_TITLE_HEIGHT + TH_KEYPAD_FIELD_VERTICAL_MARGIN,
      .width = TH_KEYPAD_FIELD_WIDTH,
      .height = TH_KEYPAD_FIELD_HEIGHT
  };

  for (int i = 0; i < 12; i++) {
    screen_fill_area(&area, TH_COLOR_FIELD_BG);

    if ((i % 3) == 2) {
      area.x = TH_FIELD_MARGIN;
      area.y += TH_KEYPAD_FIELD_HEIGHT + TH_KEYPAD_FIELD_VERTICAL_MARGIN;
    } else {
      area.x += TH_KEYPAD_FIELD_WIDTH + TH_KEYPAD_FIELD_MARGIN;
    }
  }

  area.x = TH_FIELD_MARGIN;
  area.y = TH_TITLE_HEIGHT + TH_KEYPAD_FIELD_VERTICAL_MARGIN;

  for (int i = 0; i < 12; i++) {
    while(ui_wait_keypress(portMAX_DELAY) != i) {
      continue;
    }

    screen_fill_area(&area, TH_COLOR_ACCENT);

    if ((i % 3) == 2) {
      area.x = TH_FIELD_MARGIN;
      area.y += TH_KEYPAD_FIELD_HEIGHT + TH_KEYPAD_FIELD_VERTICAL_MARGIN;
    } else {
      area.x += TH_KEYPAD_FIELD_WIDTH + TH_KEYPAD_FIELD_MARGIN;
    }
  }

  return ERR_OK;
}

static app_err_t test_colors() {
  screen_area_t area = {
      .x = 0,
      .y = TH_TITLE_HEIGHT,
      .width = (SCREEN_WIDTH / 3),
      .height = (SCREEN_HEIGHT - TH_TITLE_HEIGHT)
  };

  screen_fill_area(&area, SCREEN_COLOR_RED);

  area.x += (SCREEN_WIDTH / 3);
  screen_fill_area(&area, SCREEN_COLOR_GREEN);

  area.x += (SCREEN_WIDTH / 3);
  screen_fill_area(&area, SCREEN_COLOR_BLUE);

  while(1) {
    hal_inactivity_timer_reset();
    g_ui_ctx.battery = pwr_battery_level();
    dialog_title("R G B");

    switch(ui_wait_keypress(pdMS_TO_TICKS(COLOR_TEST_HEADER_REFRESH_MS))) {
    case KEYPAD_KEY_CANCEL:
    case KEYPAD_KEY_BACK:
      return ERR_CANCEL;
    case KEYPAD_KEY_CONFIRM:
      return ERR_OK;
    default:
      break;
    }
  }

  return ERR_OK;
}

void ui_task_entry(void* pvParameters) {
  if (screen_init() != HAL_SUCCESS) {
    vTaskSuspend(NULL);
  }

  hal_pwm_set_dutycycle(PWM_BACKLIGHT, 75);
  screen_fill_area(&screen_fullarea, SCREEN_COLOR_BLACK);

  g_ui_cmd.received = 0;

  while(1) {
    g_ui_ctx.battery = pwr_battery_level();

    if (!g_ui_cmd.received && ((ui_wait_event(portMAX_DELAY) & UI_CMD_EVT) == 0)) {
      continue;
    }

    g_ui_cmd.received = 0;

    switch(g_ui_cmd.type) {
    case UI_CMD_INFO:
      g_ui_cmd.result = dialog_info();
      break;
    case UI_CMD_PROMPT:
      g_ui_cmd.result = dialog_prompt();
      break;
    case UI_CMD_QRSCAN:
      g_ui_cmd.result = qrscan_scan();
      break;
    case UI_CMD_KEYPAD_TEST:
      g_ui_cmd.result = test_keypad();
      break;
    case UI_CMD_LCD_TEST:
      g_ui_cmd.result = test_colors();
      break;
    default:
      g_ui_cmd.result = ERR_CANCEL;
      break;
    }

    if (!g_ui_cmd.received) {
      xTaskNotifyIndexed(APP_TASK(core), CORE_EVENT_IDX, CORE_UI_EVT, eSetBits);
    }
  }
}
#endif

#include "settings_ui.h"
#include "keypad/keypad.h"
#include "ui/dialog.h"
#include "ui/theme.h"
#include "ui/ui.h"
#include "ui/ui_internal.h"

#include <stdbool.h>

#define LCD_MAX_BRIGHTNESS 100
#define LCD_MIN_BRIGHTNESS 5
#define LCD_BRIGHTNESS_STEP 5

#define LCD_BRIGHTNESS_STEPS (LCD_MAX_BRIGHTNESS / LCD_BRIGHTNESS_STEP)
#define LCD_BRIGHTNESS_BAR_WIDTH ((LCD_BRIGHTNESS_STEPS * (TH_BRIGHTNESS_SEGMENT_WIDTH + TH_BRIGHTNESS_SEGMENT_SPACING)) - TH_BRIGHTNESS_SEGMENT_SPACING)
#define LCD_BRIGHTNESS_BAR_X ((SCREEN_WIDTH - LCD_BRIGHTNESS_BAR_WIDTH) / 2)
#define LCD_BRIGHTNESS_BAR_Y TH_TITLE_HEIGHT + (((SCREEN_HEIGHT - TH_TITLE_HEIGHT - TH_NAV_HINT_HEIGHT) - TH_BRIGHTNESS_SEGMENT_HEIGHT) / 2)

void ui_progressbar_render(const screen_area_t* area, uint8_t val) {
  uint16_t completed = val == 100 ? area->width : (area->width / 100) * val;

  screen_area_t full_area = {
      .x = area->x,
      .y = area->y,
      .width = completed,
      .height = area->height
  };

  screen_area_t empty_area = {
      .x = area->x + completed,
      .y = area->y,
      .width = area->width - completed,
      .height = area->height
  };

  screen_fill_area(&full_area, TH_COLOR_PROGRESS_FG);
  screen_fill_area(&empty_area, TH_COLOR_PROGRESS_BG);
}

static void ui_brightness_render(uint8_t brightness, uint8_t old_bright) {
  screen_area_t segment = { .x = LCD_BRIGHTNESS_BAR_X, .y = LCD_BRIGHTNESS_BAR_Y, .width = TH_BRIGHTNESS_SEGMENT_WIDTH, .height = TH_BRIGHTNESS_SEGMENT_HEIGHT };
  uint16_t active_color = brightness == old_bright ? TH_BRIGHTNESS_ACTIVE_ORIGINAL : TH_BRIGHTNESS_ACTIVE_CHANGED;
  int i = 0;
  int active_count = brightness / LCD_BRIGHTNESS_STEP;

  for(i = 0; i < LCD_BRIGHTNESS_STEPS; i++) {
    screen_fill_area(&segment, i < active_count ? active_color : TH_BRIGHTNESS_INACTIVE);
    segment.x += TH_BRIGHTNESS_SEGMENT_WIDTH + TH_BRIGHTNESS_SEGMENT_SPACING;
  }
}

static void handle_lcd_change(uint8_t old_bright, bool increase) {
  do {
    if (increase) {
      if (*g_ui_cmd.params.lcd.brightness < LCD_MAX_BRIGHTNESS) {
        (*g_ui_cmd.params.lcd.brightness) += LCD_BRIGHTNESS_STEP;
      }
    } else {
      if (*g_ui_cmd.params.lcd.brightness > LCD_MIN_BRIGHTNESS) {
        (*g_ui_cmd.params.lcd.brightness) -= LCD_BRIGHTNESS_STEP;
      }
    }

    hal_pwm_set_dutycycle(PWM_BACKLIGHT, *g_ui_cmd.params.lcd.brightness);
    ui_brightness_render(*g_ui_cmd.params.lcd.brightness, old_bright);
    vTaskDelay(pdMS_TO_TICKS(50));
  } while(g_ui_ctx.keypad.last_key_long && !g_ui_ctx.keypad.last_key_released);
}

app_err_t settings_ui_lcd_brightness() {
  dialog_title(LSTR(LCD_BRIGHTNESS_TITLE));
  dialog_footer(TH_TITLE_HEIGHT);

  const glyph_t* left_chevron = screen_lookup_glyph(TH_FONT_TEXT, SYM_LEFT_CHEVRON);

  screen_text_ctx_t ctx = {
      .bg = TH_COLOR_TEXT_BG,
      .fg = TH_COLOR_TEXT_FG,
      .font = TH_FONT_TEXT,
      .x = LCD_BRIGHTNESS_BAR_X - left_chevron->xAdvance - TH_BRIGHTNESS_CHEVRON_MARGIN,
      .y = LCD_BRIGHTNESS_BAR_Y + ((TH_BRIGHTNESS_SEGMENT_HEIGHT - (TH_FONT_TEXT)->yAdvance) / 2)
  };

  screen_draw_glyph(&ctx, left_chevron);

  ctx.x = LCD_BRIGHTNESS_BAR_X + LCD_BRIGHTNESS_BAR_WIDTH + TH_BRIGHTNESS_CHEVRON_MARGIN;
  screen_draw_char(&ctx, SYM_RIGHT_CHEVRON);

  uint8_t old_bright = *g_ui_cmd.params.lcd.brightness;
  ui_brightness_render(*g_ui_cmd.params.lcd.brightness, old_bright);

  dialog_nav_hints(ICON_NAV_CANCEL, ICON_NAV_CONFIRM);

  while(1) {
    switch(ui_wait_keypress(portMAX_DELAY)) {
    case KEYPAD_KEY_CANCEL:
      return ERR_CANCEL;
    case KEYPAD_KEY_BACK:
      return ERR_CANCEL;
    case KEYPAD_KEY_CONFIRM:
      return ERR_OK;
    case KEYPAD_KEY_LEFT:
      handle_lcd_change(old_bright, false);
      break;
    case KEYPAD_KEY_RIGHT:
      handle_lcd_change(old_bright, true);
      break;
    default:
      break;
    }
  }
}

static bool updating_progress() {
  uint32_t evt = ui_wait_event(portMAX_DELAY);

  if (evt & UI_CMD_EVT) {
    if (g_ui_cmd.type != UI_CMD_PROGRESS) {
      g_ui_cmd.received = 1;
      return false;
    }
  }

  return true;
}

app_err_t settings_ui_update_progress() {
  dialog_title(g_ui_cmd.params.progress.title);
  dialog_footer(TH_TITLE_HEIGHT);
  screen_area_t progress_area = {
      .x = TH_PROGRESS_LEFT_MARGIN,
      .y = TH_TITLE_HEIGHT + TH_PROGRESS_VERTICAL_MARGIN,
      .width = TH_PROGRESS_WIDTH,
      .height = TH_PROGRESS_HEIGHT
  };

  screen_text_ctx_t ctx = {
      .font = TH_FONT_TEXT,
      .fg = TH_COLOR_TEXT_FG,
      .bg = TH_COLOR_TEXT_BG,
      .x = 0,
      .y = TH_TITLE_HEIGHT + TH_PROGRESS_WARN_VERTICAL_MARGIN,
  };

  screen_draw_centered_string(&ctx, LSTR(FW_UPGRADE_WARNING));

  do {
    ui_progressbar_render(&progress_area, g_ui_cmd.params.progress.value);
  } while(updating_progress());

  return ERR_OK;
}

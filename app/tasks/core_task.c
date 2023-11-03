#ifndef TEST_APP
#include "core/core.h"
#include "core/card.h"
#include "core/settings.h"
#include "keycard/keycard.h"
#include "pwr.h"
#include "usb/usb.h"

static inline void core_action_run(i18n_str_id_t menu) {
  switch(menu) {
  // Top Level
  case MENU_QRCODE:
    core_qr_run();
    break;
  case MENU_DISPLAY_PUBLIC:
    core_display_public();
    break;
  // Keycard
  case MENU_CARD_NAME:
    card_change_name();
    break;
  case MENU_CHANGE_PIN:
    card_change_pin();
    break;
  case MENU_CHANGE_PUK:
    card_change_puk();
    break;
  case MENU_CHANGE_PAIRING:
    card_change_pairing();
    break;
  case MENU_RESET_CARD:
    card_reset();
    break;
  // Device
  case MENU_INFO:
    device_info();
    break;
  case MENU_DB_UPDATE:
    updater_database_run();
    break;
  case MENU_DEV_AUTH:
    device_auth_run();
    break;
  // Settings
  case MENU_BRIGHTNESS:
    settings_lcd_brightness();
    break;
  case MENU_SET_OFF_TIME:
    settings_set_off_time();
    break;
  case MENU_USB:
    settings_usb_onoff();
    break;
  default:
    //unknown commands
    break;
  }
}

void core_task_entry(void* pvParameters) {
  if (hal_gpio_get(GPIO_SMARTCARD_PRESENT) == GPIO_RESET) {
    pwr_shutdown();
  }

  keycard_init(&g_core.keycard);
  keycard_activate(&g_core.keycard);

  if (g_core.keycard.sc.state != SC_READY) {
    pwr_reboot();
  }

  g_core.ready = true;

  usb_start_if_connected();

  while(1) {
    i18n_str_id_t selected = MENU_QRCODE;
    const char* title = g_core.keycard.name[0] ? g_core.keycard.name : LSTR(MENU_TITLE);

    switch(ui_menu(title, &menu_mainmenu, &selected, 1)) {
    case CORE_EVT_USB_CMD:
      core_usb_run();
      break;
    case CORE_EVT_UI_OK:
      core_action_run(selected);
      break;
    case CORE_EVT_UI_CANCELLED:
    default:
      break;
    }
  }
}
#endif

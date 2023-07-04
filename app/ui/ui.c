#include "app_tasks.h"
#include "core/core.h"
#include "error.h"
#include "ui.h"
#include "ui_internal.h"

static inline core_evt_t ui_signal_wait(uint8_t allow_usb) {
  xTaskNotifyIndexed(APP_TASK(ui), UI_NOTIFICATION_IDX, UI_CMD_EVT, eSetBits);
  return core_wait_event(allow_usb);
}

core_evt_t ui_qrscan(struct eth_sign_request* sign_request) {
  g_ui_cmd.type = UI_CMD_QRSCAN;
  g_ui_cmd.params.qrscan.out = sign_request;
  return ui_signal_wait(0);
}

core_evt_t ui_menu(const menu_t* menu, i18n_str_id_t* selected) {
  g_ui_cmd.type = UI_CMD_MENU;
  g_ui_cmd.params.menu.menu = menu;
  g_ui_cmd.params.menu.selected = selected;
  return ui_signal_wait(1);
}

core_evt_t ui_display_tx(const txContent_t* tx, uint32_t chain_id) {
  g_ui_cmd.type = UI_CMD_DISPLAY_TXN;
  g_ui_cmd.params.txn.tx = tx;
  g_ui_cmd.params.txn.chain_id = chain_id;
  return ui_signal_wait(0);
}

core_evt_t ui_display_msg(const uint8_t* msg, uint32_t len) {
  g_ui_cmd.type = UI_CMD_DISPLAY_MSG;
  g_ui_cmd.params.msg.data = msg;
  g_ui_cmd.params.msg.len = len;
  return ui_signal_wait(0);
}

core_evt_t ui_display_qr(const uint8_t* data, uint32_t len, ur_type_t type) {
  g_ui_cmd.type = UI_CMD_DISPLAY_QR;
  g_ui_cmd.params.qrout.data = data;
  g_ui_cmd.params.qrout.len = len;
  g_ui_cmd.params.qrout.type = type;
  return ui_signal_wait(0);
}

void ui_card_inserted() {

}

void ui_card_removed() {
}

void ui_card_transport_error() {
  g_ui_cmd.type = UI_CMD_INFO;
  g_ui_cmd.params.info.dismissable = 0;
  g_ui_cmd.params.info.title = INFO_ERROR_TITLE;
  g_ui_cmd.params.info.msg = LSTR(INFO_CARD_ERROR_MSG);
  ui_signal_wait(0);
}

void ui_card_accepted() {
}

void ui_keycard_wrong_card() {
  g_ui_cmd.type = UI_CMD_INFO;
  g_ui_cmd.params.info.dismissable = 0;
  g_ui_cmd.params.info.title = INFO_ERROR_TITLE;
  g_ui_cmd.params.info.msg = LSTR(INFO_NOT_KEYCARD);
  ui_signal_wait(0);
}

void ui_keycard_not_initialized() {
  g_ui_cmd.type = UI_CMD_INFO;
  g_ui_cmd.params.info.dismissable = 1;
  g_ui_cmd.params.info.title = INFO_NEW_CARD_TITLE;
  g_ui_cmd.params.info.msg = LSTR(INFO_NEW_CARD);
  ui_signal_wait(0);
}

void ui_keycard_init_failed() {
}

void ui_keycard_no_keys() {
}

void ui_keycard_ready() {
}

void ui_keyard_paired() {
}

void ui_keycard_already_paired() {
}

void ui_keycard_pairing_failed() {
}

void ui_keycard_flash_failed() {
}

void ui_keycard_secure_channel_failed() {
}

void ui_keycard_secure_channel_ok() {
}

void ui_keycard_wrong_pin() {
}

void ui_keycard_pin_ok() {
}

void ui_keycard_puk_ok() {
}

void ui_keycard_wrong_puk() {
}

core_evt_t ui_prompt_try_puk() {
  return CORE_EVT_UI_OK;
}

core_evt_t ui_confirm_factory_reset() {
  return CORE_EVT_UI_OK;
}

core_evt_t ui_read_pin(uint8_t* out, int8_t retries) {
  g_ui_cmd.type = UI_CMD_INPUT_PIN;
  g_ui_cmd.params.input_pin.retries = retries;
  g_ui_cmd.params.input_pin.out = out;

  return ui_signal_wait(0);
}

core_evt_t ui_read_puk(uint8_t* out, int8_t retries) {
  return CORE_EVT_UI_CANCELLED;
}

core_evt_t ui_read_pairing(uint8_t* pairing, uint32_t *len) {
  return CORE_EVT_UI_OK;
}

void ui_seed_loaded() {
}

core_evt_t ui_backup_mnemonic(const char* mnemonic) {
  return CORE_EVT_UI_OK;
}

core_evt_t ui_read_mnemonic(uint16_t* indexes, uint32_t* len) {
  *len = 12;
  return CORE_EVT_UI_CANCELLED;
}

core_evt_t ui_confirm_eth_address(const char* address) {
  return CORE_EVT_UI_OK;
}

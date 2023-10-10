#include "card.h"
#include "core.h"
#include "keycard/keycard_cmdset.h"
#include "pwr.h"

void card_change_name() {
  char name[KEYCARD_NAME_MAX_LEN + 1];
  uint8_t len = KEYCARD_NAME_MAX_LEN;

  if (ui_read_string(LSTR(CARD_NAME_TITLE), name, &len) != CORE_EVT_UI_OK) {
    return;
  }

  if (keycard_set_name(&g_core.keycard, name) != ERR_OK) {
    ui_card_transport_error();
  }
}

void card_change_pin() {
  SC_BUF(pin, KEYCARD_PIN_LEN);

  if (ui_read_pin(pin, PIN_NEW_CODE) != CORE_EVT_UI_OK) {
    return;
  }

  app_err_t err = keycard_cmd_change_credential(&g_core.keycard, KEYCARD_PIN, pin, KEYCARD_PIN_LEN);
  memset(pin, 0, KEYCARD_PIN_LEN);

  if (err != ERR_OK) {
    ui_card_transport_error();
  }
}

void card_change_puk() {
  SC_BUF(puk, KEYCARD_PUK_LEN);

  if (ui_read_puk(puk, PUK_NEW_CODE) != CORE_EVT_UI_OK) {
    return;
  }

  app_err_t err = keycard_cmd_change_credential(&g_core.keycard, KEYCARD_PUK, puk, KEYCARD_PUK_LEN);
  memset(puk, 0, KEYCARD_PUK_LEN);

  if (err != ERR_OK) {
    ui_card_transport_error();
  }
}

void card_change_pairing() {
  SC_BUF(password, KEYCARD_PAIRING_PASS_MAX_LEN);
  uint8_t len = KEYCARD_PAIRING_PASS_MAX_LEN;

  if (ui_read_string(LSTR(PAIRING_CREATE_TITLE), (char *) password, &len) != CORE_EVT_UI_OK) {
    return;
  }

  uint8_t pairing[32];

  keycard_pairing_password_hash(password, len, pairing);
  memset(password, 0, len);

  app_err_t err = keycard_cmd_change_credential(&g_core.keycard, KEYCARD_PAIRING, pairing, 32);

  if (err != ERR_OK) {
    ui_card_transport_error();
  }
}

void card_reset() {
  keycard_factoryreset(&g_core.keycard);
  pwr_reboot();
}
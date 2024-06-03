#ifndef __I18N__
#define __I18N__

extern const char *const i18n_english_strings[];

typedef enum {
  // Main menu
  MENU_TITLE = 0,
  MENU_QRCODE,
  MENU_CONNECT,
  MENU_ADDRESSES,
  MENU_SETTINGS,
  MENU_HELP,

  // Connect menu
  MENU_CONNECT_EIP4527,
  MENU_CONNECT_MULTICOIN,

  // Addresses menu
  MENU_ETHEREUM,
  MENU_BITCOIN,

  // Settings menu
  MENU_DEVICE,
  MENU_KEYCARD,

  // Keycard menu
  MENU_CARD_NAME,
  MENU_CHANGE_PIN,
  MENU_CHANGE_PUK,
  MENU_CHANGE_PAIRING,
  MENU_RESET_CARD,
  MENU_UNBLOCK_PUK,

  // Device menu
  MENU_INFO,
  MENU_DEV_AUTH,
  MENU_DB_UPDATE,

  // Settings menu
  MENU_BRIGHTNESS,
  MENU_SET_OFF_TIME,
  MENU_USB,

  // TX Confirmation
  TX_CONFIRM_TITLE,
  TX_CONFIRM_ERC20_TITLE,
  TX_CHAIN,
  TX_ADDRESS,
  TX_AMOUNT,
  TX_FEE,
  TX_SIGNER,
  TX_DATA,
  TX_DATA_NONE,
  TX_DATA_ERC20,
  TX_DATA_PRESENT,

  // MSG Confirmation
  MSG_CONFIRM_TITLE,
  MSG_LABEL,

  // EIP712 Confirmation
  EIP712_CONFIRM_TITLE,
  EIP712_CONTRACT,
  EIP712_NAME,

  // QR output
  QR_SIGNATURE_TITLE,
  QR_DEVAUTH_TITLE,
  QR_CONNECT_EIP4527_TITLE,
  QR_CONNECT_MULTIACCOUNT_TITLE,

  // PIN input
  PIN_INPUT_TITLE,
  PIN_WRONG_WARNING,
  PIN_CREATE_TITLE,
  PIN_LABEL_REMAINING_ATTEMPTS,
  PIN_LABEL_REPEAT,
  PIN_LABEL_MISMATCH,
  PIN_CHANGE_SUCCESS,

  // PUK input
  PUK_INPUT_TITLE,
  PUK_WRONG_WARNING,
  PUK_CREATE_TITLE,
  PUK_CHANGE_SUCCESS,

  // Pairing input
  PAIRING_INPUT_TITLE,
  PAIRING_CREATE_TITLE,
  PAIRING_CHANGE_SUCCESS,
  PAIRING_CHANGE_PROMPT,
  PAIRING_CHANGE_TITLE,

  // Name input
  CARD_NAME_TITLE,
  CARD_NAME_CHANGE_SUCCESS,

  // Factory reset
  FACTORY_RESET_TITLE,
  FACTORY_RESET_WARNING,

  // Info messages
  INFO_CARD_ERROR_MSG,
  INFO_NOT_KEYCARD,
  INFO_NOT_GENUINE,
  INFO_OLD_KEYCARD,
  INFO_NEW_CARD,
  INFO_NO_PAIRING_SLOTS,
  INFO_WRONG_CARD,
  INFO_MALFORMED_DATA,
  INFO_KEYCARD_BLOCKED,

  // DB Update
  DB_UPDATE_TITLE,
  DB_UPDATE_OK,
  DB_UPDATE_INVALID,
  DB_UPDATE_ERROR,
  DB_UPDATE_PROMPT,
  DB_UPDATE_NO_DB,
  DB_UPDATE_CONFIRM,

  // FW Upgrade
  FW_UPGRADE_TITLE,
  FW_UPGRADE_INVALID,
  FW_UPGRADE_CONFIRM,

  // Mnemonic input
  MNEMO_TITLE,
  MENU_MNEMO_12WORDS,
  MENU_MNEMO_18WORDS,
  MENU_MNEMO_24WORDS,
  MENU_MNEMO_IMPORT,
  MENU_MNEMO_GENERATE,
  MNEMO_WORD_TITLE,
  MNEMO_BACKUP_TITLE,
  MNENO_MISMATCH,

  // Device verification
  DEV_AUTH_INVALID_CHALLENGE,
  DEV_AUTH_INVALID_AUTH,
  DEV_AUTH_INFO_SUCCESS,
  DEV_AUTH_INFO_WARNING,

  // LCD settings
  LCD_BRIGHTNESS_TITLE,

  // Auto off times
  AUTO_OFF_TITLE,
  MENU_OFF_3MINS,
  MENU_OFF_5MINS,
  MENU_OFF_10MINS,
  MENU_OFF_30MINS,
  MENU_OFF_NEVER,

  // USB enable
  USB_ENABLE_TITLE,
  MENU_OFF,
  MENU_ON,

  // Device info
  DEVICE_INFO_FW,
  DEVICE_INFO_DB,
  DEVICE_INFO_SN,
  DEVICE_INFO_NEW_FW,
  DEVICE_INFO_NEW_DB,

  // Hints
  HINT_CANCEL,
  HINT_CONFIRM,
} i18n_str_id_t;

//TODO: replace with proper lookup
#define LSTR(__ID__) i18n_english_strings[__ID__]

#endif

#ifndef __I18N__
#define __I18N__

extern const char** const i18n_strings[];
extern const char *const i18n_english_strings[];

typedef enum {
  // Main menu
  MENU_QRCODE = 0,
  MENU_CONNECT,
  MENU_ADDRESSES,
  MENU_SETTINGS,
  MENU_HELP,

  // Connect menu
  MENU_CONNECT_EIP4527,
  MENU_CONNECT_BITCOIN,
  MENU_CONNECT_BITCOIN_TESTNET,
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
  TX_CONFIRM_TRANSFER,
  TX_CONFIRM_APPROVAL,
  TX_CHAIN,
  TX_ADDRESS,
  TX_SPENDER,
  TX_AMOUNT,
  TX_SIGNED_AMOUNT,
  TX_MULTIPLE_RECIPIENT,
  TX_SIGHASH_WARNING,
  TX_FEE,
  TX_SIGNER,
  TX_DATA,
  TX_NO,
  TX_YES,
  TX_INPUT,
  TX_OUTPUT,
  TX_SIGNED,
  TX_SIGN_SCHEME,
  TX_SIGN_ALL,
  TX_SIGN_NONE,
  TX_SIGN_SINGLE,
  TX_SIGN_ANYONECANPAY,
  TX_CHANGE,

  // MSG Confirmation
  MSG_CONFIRM_TITLE,
  MSG_LABEL,

  // EIP712 Confirmation
  EIP712_CONFIRM_TITLE,
  EIP712_CONTRACT,
  EIP712_NAME,

  // QR output
  QR_SCAN_WALLET_TITLE,
  QR_DEVAUTH_TITLE,
  QR_ADDRESS_ETH_TITLE,
  QR_ADDRESS_BTC_TITLE,

  // PIN input
  PIN_INPUT_TITLE,
  PIN_WRONG_WARNING,
  PIN_CREATE_TITLE,
  PIN_LABEL_REMAINING_ATTEMPTS,
  PIN_LABEL_REPEAT,
  PIN_CHANGE_SUCCESS,

  // PUK input
  PUK_INPUT_TITLE,
  PUK_WRONG_WARNING,
  PUK_CREATE_TITLE,
  PUK_LABEL_REPEAT,
  PUK_CHANGE_SUCCESS,
  PUK_CHANGE_PROMPT,

  // Pairing input
  PAIRING_INPUT_TITLE,
  PAIRING_CREATE_TITLE,
  PAIRING_CHANGE_SUCCESS,
  PAIRING_CHANGE_PROMPT,

  // Name input
  CARD_NAME_CHANGE_SUCCESS,

  // Input hints
  INPUT_NAV_EXIT,
  INPUT_NAV_SAVE,
  INPUT_NAV_PROCEED,

  // Factory reset
  FACTORY_RESET_TITLE,
  FACTORY_RESET_WARNING,

  // Info messages
  INFO_CARD_ERROR_MSG,
  INFO_CARD_ERROR_SUB,
  INFO_NOT_KEYCARD_MSG,
  INFO_NOT_KEYCARD_SUB,
  INFO_NOT_GENUINE_MSG,
  INFO_NOT_GENUINE_SUB,
  INFO_OLD_KEYCARD_MSG,
  INFO_OLD_KEYCARD_SUB,
  INFO_NO_PAIRING_SLOTS_MSG,
  INFO_NO_PAIRING_SLOTS_SUB,
  INFO_WRONG_CARD_MSG,
  INFO_WRONG_CARD_SUB,
  INFO_MALFORMED_DATA_MSG,
  INFO_MALFORMED_DATA_SUB,
  INFO_KEYCARD_BLOCKED,
  INFO_KEYCARD_LOADED_MSG,
  INFO_KEYCARD_LOADED_SUB,
  INFO_KEYCARD_BAD_SEED_MSG,
  INFO_KEYCARD_BAD_SEED_SUB,

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
  FW_UPGRADE_WARNING,
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
  MNEMO_WORD_BACKUP_TITLE,
  MNEMO_BACKUP_TITLE,
  MNEMO_BACKUP_PROMPT,
  MNEMO_MISMATCH,
  MNEMO_MISMATCH_LIMIT,
  MNEMO_MISMATCH_RETRY,
  MNEMO_VERIFY_TITLE,
  MNEMO_VERIFY_PROMPT,

  // Device verification
  DEV_AUTH_INVALID_QR,
  DEV_AUTH_INVALID_CHALLENGE_SUB,
  DEV_AUTH_INVALID_AUTH_SUB,
  DEV_AUTH_INFO_SUCCESS_MSG,
  DEV_AUTH_INFO_SUCCESS_SUB,

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

  INVALID_STR = 0xffff
} i18n_str_id_t;

#define LSTR(__ID__) (*i18n_strings)[__ID__]

void i18n_set_strings(const char *const strings[]);

#endif

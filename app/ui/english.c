#include "i18n.h"

const char *const i18n_english_strings[] = {
    // Main menu
    "Keycard Pro",
    "Scan QR transaction",
    "Connect software wallet",
    "Addresses",
    "Settings",
    "Help",

    // Connect menu
    "EVM-chain wallet",
    "OKX Wallet",

    // Addresses menu
    "Ethereum",
    "Bitcoin",

    // Settings menu
    "Device",
    "Keycard",

    // Keycard menu
    "Set card name",
    "Change PIN",
    "Change PUK",
    "Change pairing pass",
    "Factory reset card",
    "Unblock with PUK",

    // Device menu
    "Information",
    "Verification",
    "Update ERC20 db",
    "Set brightness",
    "Auto-off time",
    "USB-data",

    // TX
    "Sign transaction",
    "Sign ERC20 transfer",
    "Chain",
    "To",
    "Amount",
    "Fee",
    "Signer",
    "Data",
    "No",
    "Yes (ERC20)",
    "Yes",

    // MSG Confirmation
    "Sign message",
    "Message",

    // EIP712 Confirmation
    "Sign EIP712",
    "Contract",
    "Name",

    // QR output
    "Scan with your wallet",
    "Scan to verify",
    "Scan with your EVM-chain wallet",
    "Scan with your OKX wallet",

    // PIN input
    "Insert your PIN",
    "Wrong PIN. Please try again.",
    "Choose a new PIN",
    "Remaining attempts: ",
    "Repeat the PIN",
    "PINs don't match",
    "PIN changed successfully",

    // PUK input
    "Insert your PUK",
    "Wrong PUK. Please try again.",
    "Choose a new PUK",
    "PUK changed successfully",

    // Pairing input
    "Insert your pairing password",
    "Input new pairing password",
    "Pairing password changed successfully",
    "If you change the pairing pass from the default, you will have to manually enter it on pairing requests between your current Keycard and any other wallet and app.",
    "Change pairing password",

    // Name input
    "Set the Keycard name",
    "Card name changed successfully",

    // Factory reset
    "Card factory reset",
    "Factory reset will permanently erase all keys on your card.\nEnsure you back up your seed phrase. The device will restart after resetting.",

    // Info messages
    "Communication with the card lost.\n\nPlease remove it and insert it again",
    "The inserted card does not appear to be a Keycard. Please replace it with a Keycard",
    "Failed to verify genuineness of this card. Do not press OK unless you loaded a custom Keycard applet on this card yourself",
    "This Keycard has an old version of the applet installed. Please replace it with a newer one",
    "We will now proceed initializing your Keycard.\n\nYou will be required to choose a PIN for your card.\n\nPress OK to continue.",
    "You can't connect this Keycard to new devices because all pairing slots are full.\nPlease use it with a device with which you used it previously or factory reset the card.",
    "This QR is not for this key pair.\nTry again using a different Keycard.",
    "The content of this QR is malformed or unsupported. Please generate a new one.",
    "Keycard blocked",

    // DB Update
    "Updating database...",
    "The database update was successful.",
    "The new database data seems to be invalid.\n Check that you are using the correct site and try again.",
    "Internal error while writing the new data, please try again.",
    "Enter the version number below on the update website to generate the update QR, then press OK to scan.\n\n",
    "No database found. Please use the USB cable to perform its installation.",
    "Proceed updating the database?\n\n",

    // FW Upgrade
    "Upgrading firmware...",
    "The uploaded firmware's signature does not match. Please make sure you are using the official website or app.",
    "Do you want to upgrade your firmware?\n\n",

    // Mnemonic input
    "Seed loading",
    "I have a 12 word seed",
    "I have a 18 word seed",
    "I have a 24 word seed",
    "I want a new seed",
    "Enter word #",
    "Write down and keep safe!",
    "Word does not match, please try again.",

    // Device verification
    "Invalid verification QR. Please check the website you are on and try again.",
    "The response from the server is invalid. Ignore the verification results, make sure you go on the correct site and try again.",
    "The verification was successful and this was the first time this unit has been verified. You can safely use the device.",
    "The verification succeeded, however this wasn't the first time the unit has been verified. If you remember already verifying this device before, then there is nothing to worry about. Otherwise please contact us.",

    // LCD settings
    "LCD brightness",

    // Auto off times
    "Set auto off timeout",
    "3 minutes",
    "5 minutes",
    "10 minutes" ,
    "30 minutes",
    "Never",

    // USB enable
    "Enable USB data transfer",
    "Off",
    "On",

    // Device info
    "Firmware version: ",
    "Database version: ",
    "S/N: ",
    "New firmware version: ",
    "New database version: ",

    // Hints
    "Long press C to cancel",
    "Long press OK to confirm",
};

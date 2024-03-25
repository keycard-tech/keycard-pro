#ifndef __THEME__
#define __THEME__

#include "font/font.h"
#include "screen/screen.h"

#define TH_DEF_LEFT_MARGIN 4

#define TH_COLOR_BG SCREEN_RGB(75, 82, 111)
#define TH_COLOR_FG SCREEN_COLOR_WHITE

#define TH_COLOR_QR_BG TH_COLOR_BG
#define TH_COLOR_QR_NOT_FOUND SCREEN_COLOR_RED
#define TH_COLOR_QR_NOT_DECODED SCREEN_COLOR_ORANGE
#define TH_COLOR_QR_OK SCREEN_COLOR_GREEN

#define TH_COLOR_MENU_BG TH_COLOR_BG
#define TH_COLOR_MENU_FG TH_COLOR_FG
#define TH_COLOR_MENU_SELECTED_BG SCREEN_RGB(37, 41, 56)
#define TH_COLOR_MENU_SELECTED_FG TH_COLOR_FG
#define TH_COLOR_MENU_MARK TH_COLOR_FG

#define TH_COLOR_SEP SCREEN_RGB(189, 193, 211)

#define TH_COLOR_TITLE_BG SCREEN_RGB(8, 183, 156)
#define TH_COLOR_TITLE_FG TH_COLOR_FG

#define TH_COLOR_LABEL_BG TH_COLOR_BG
#define TH_COLOR_LABEL_FG SCREEN_RGB(9, 217, 185)

#define TH_COLOR_DATA_BG TH_COLOR_BG
#define TH_COLOR_DATA_FG TH_COLOR_FG

#define TH_COLOR_TEXT_BG TH_COLOR_BG
#define TH_COLOR_TEXT_FG TH_COLOR_FG

#define TH_COLOR_PIN_FIELD_BG SCREEN_RGB(37, 41, 56)
#define TH_COLOR_PIN_FIELD_SELECTED_BG SCREEN_RGB(8, 183, 156)
#define TH_COLOR_PIN_FIELD_FG TH_COLOR_FG

#define TH_COLOR_PROGRESS_FG SCREEN_RGB(8, 183, 156)
#define TH_COLOR_PROGRESS_BG SCREEN_RGB(37, 41, 56)

#define TH_FONT_MENU &free_sans_18px
#define TH_FONT_LABEL &free_sans_18px
#define TH_FONT_DATA &plat_nomor_16px
#define TH_FONT_TITLE &free_sans_18px
#define TH_FONT_TEXT &free_sans_18px
#define TH_FONT_ICONS &icons_28px

#define TH_MENU_HEIGHT 30
#define TH_MENU_LEFT_MARGIN TH_DEF_LEFT_MARGIN
#define TH_MENU_RIGHT_MARGIN 8
#define TH_MENU_MARK_WIDTH 12
#define TH_MENU_MARK_HEIGHT 12

#define TH_SEP_HEIGHT 2

#define TH_LABEL_HEIGHT 26
#define TH_LABEL_LEFT_MARGIN TH_DEF_LEFT_MARGIN

#define TH_DATA_HEIGHT 26
#define TH_DATA_LEFT_MARGIN TH_DEF_LEFT_MARGIN

#define TH_INLINE_DATA_LEFT_MARGIN 72

#define TH_TITLE_HEIGHT 28
#define TH_TITLE_LEFT_MARGIN TH_DEF_LEFT_MARGIN

#define TH_TEXT_HORIZONTAL_MARGIN TH_DEF_LEFT_MARGIN
#define TH_TEXT_VERTICAL_MARGIN 8

#define TH_QRCODE_VERTICAL_MARGIN 8

#define TH_PIN_FIELD_HEIGHT 30
#define TH_PIN_FIELD_WIDTH 30
#define TH_PIN_FIELD_VERTICAL_MARGIN 16
#define TH_PIN_FIELD_DIGIT_MARGIN TH_DEF_LEFT_MARGIN
#define TH_PUK_FIELD_VERTICAL_MARGIN 4

#define TH_KEYBOARD_KEY_SIZE 32
#define TH_KEYBOARD_KEY_BG SCREEN_RGB(37, 41, 56)
#define TH_KEYBOARD_KEY_SELECTED_BG SCREEN_RGB(8, 183, 156)

#define TH_TEXT_FIELD_BG SCREEN_RGB(37, 41, 56)
#define TH_TEXT_FIELD_FG TH_COLOR_FG
#define TH_TEXT_FIELD_SUGGESTION_FG SCREEN_RGB(127, 127, 127)
#define TH_TEXT_FIELD_MARGIN 8
#define TH_TEXT_FIELD_INNER_LEFT_MARGIN 4

#define TH_TEXT_FIELD_HEIGHT 30

#define TH_MNEMONIC_TOP_MARGIN 8
#define TH_MNEMONIC_LEFT_MARGIN 5
#define TH_MNEMONIC_FIELD_WIDTH 100

#define TH_PROGRESS_HEIGHT 20
#define TH_PROGRESS_WIDTH 300
#define TH_PROGRESS_LEFT_MARGIN 10
#define TH_PROGRESS_VERTICAL_MARGIN 10

#endif

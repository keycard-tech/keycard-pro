#ifndef __THEME__
#define __THEME__

#include "font/font.h"
#include "screen/screen.h"

#define TH_SCREEN_MARGIN 16

#define TH_COLOR_BG SCREEN_COLOR_BLACK
#define TH_COLOR_FG SCREEN_COLOR_WHITE
#define TH_COLOR_ACCENT SCREEN_RGB(0xff, 0x50, 0x00)
#define TH_COLOR_FIELD_BG SCREEN_RGB(37, 41, 56)
#define TH_COLOR_INACTIVE SCREEN_RGB(0x7d, 0x7b, 0x8c)
#define TH_COLOR_SUCCESS SCREEN_RGB(0x00, 0xff, 0x00)
#define TH_COLOR_ERROR SCREEN_RGB(0xff, 0x00, 0x00)

#define TH_COLOR_QR_BG TH_COLOR_BG
#define TH_COLOR_QR_NOT_FOUND TH_COLOR_ERROR
#define TH_COLOR_QR_NOT_DECODED SCREEN_RGB(0xff, 0xd2, 0x32)
#define TH_COLOR_QR_OK TH_COLOR_SUCCESS
#define TH_COLOR_QR_EMPTY_TICK TH_COLOR_INACTIVE

#define TH_COLOR_MENU_BG TH_COLOR_BG
#define TH_COLOR_MENU_FG TH_COLOR_FG
#define TH_COLOR_MENU_SELECTED_BG TH_COLOR_BG
#define TH_COLOR_MENU_SELECTED_FG TH_COLOR_ACCENT
#define TH_COLOR_MENU_MARK TH_COLOR_FG

#define TH_COLOR_TITLE_BG TH_COLOR_BG
#define TH_COLOR_TITLE_FG TH_COLOR_INACTIVE
#define TH_COLOR_TITLE_ICON_FG TH_COLOR_FG

#define TH_COLOR_LABEL_BG TH_COLOR_BG
#define TH_COLOR_LABEL_FG TH_COLOR_INACTIVE

#define TH_COLOR_DATA_BG TH_COLOR_BG
#define TH_COLOR_DATA_FG TH_COLOR_FG

#define TH_COLOR_TEXT_BG TH_COLOR_BG
#define TH_COLOR_TEXT_FG TH_COLOR_FG

#define TH_COLOR_PROGRESS_BG TH_COLOR_FIELD_BG
#define TH_COLOR_PROGRESS_FG TH_COLOR_ACCENT

#define TH_BRIGHTNESS_ACTIVE TH_COLOR_ACCENT
#define TH_BRIGHTNESS_INACTIVE TH_COLOR_INACTIVE

#define TH_FONT_MENU &shell_16px
#define TH_FONT_LABEL &shell_16px
#define TH_FONT_DATA &shell_16px
#define TH_FONT_TITLE &shell_16px
#define TH_FONT_TEXT &shell_16px
#define TH_FONT_INFO &inter_20px
#define TH_FONT_ICONS &icons_28px
#define TH_NAV_ICONS &navigation_24px
#define TH_INFO_ICONS &msg_40px

#define TH_MENU_HEIGHT 28
#define TH_MENU_VERTICAL_MARGIN 4
#define TH_MENU_CONSTRAST_PADDING 4
#define TH_MENU_LEFT_MARGIN TH_SCREEN_MARGIN
#define TH_MENU_RIGHT_MARGIN 8
#define TH_MENU_MARK_WIDTH 12
#define TH_MENU_MARK_HEIGHT 12

#define TH_LABEL_WIDTH 88
#define TH_LABEL_HEIGHT 22
#define TH_DATA_HEIGHT TH_LABEL_HEIGHT

#define TH_TITLE_HEIGHT 36
#define TH_TITLE_LEFT_MARGIN TH_SCREEN_MARGIN
#define TH_TITLE_TOP_MARGIN (TH_SCREEN_MARGIN - 2)
#define TH_TITLE_ICON_LEFT_MARGIN 280
#define TH_TITLE_ICON_TOP_MARGIN (TH_SCREEN_MARGIN - 4)

#define TH_TEXT_HORIZONTAL_MARGIN TH_SCREEN_MARGIN
#define TH_TEXT_VERTICAL_MARGIN 2

#define TH_QRCODE_VERTICAL_MARGIN 2
#define TH_QRCODE_ADDR_MARGIN 52
#define TH_QRSCAN_INDICATOR_MARGIN 20
#define TH_QRSCAN_TICK_WIDTH 16
#define TH_QRSCAN_TICK_HEIGHT 2
#define TH_QRSCAN_TICK_BOTTOM (SCREEN_HEIGHT - 80)
#define TH_QRSCAN_TICK_SPACING 4

#define TH_PIN_FIELD_VERTICAL_MARGIN 16
#define TH_PIN_DIGIT_MARGIN 6
#define TH_PUK_FIELD_VERTICAL_MARGIN 4

#define TH_KEYBOARD_TOP 78
#define TH_KEYBOARD_KEY_SIZE 28
#define TH_KEYBOARD_SPACEBAR_WIDTH 118
#define TH_KEYBOARD_KEY_MARGIN 2
#define TH_KEYBOARD_KEY_BG SCREEN_RGB(0x0d, 0x0d, 0x0d)
#define TH_KEYBOARD_KEY_SELECTED_BG TH_COLOR_ACCENT
#define TH_KEYBOARD_KEY_FG TH_COLOR_FG
#define TH_KEYBOARD_KEY_SELECTED_FG TH_COLOR_FG

#define TH_TEXT_FIELD_BG TH_COLOR_BG
#define TH_TEXT_FIELD_FG TH_COLOR_FG
#define TH_TEXT_FIELD_SUGGESTION_FG TH_COLOR_INACTIVE
#define TH_TEXT_FIELD_MARGIN 8
#define TH_TEXT_FIELD_HINT_MARGIN 16
#define TH_TEXT_FIELD_TOP 44
#define TH_TEXT_FIELD_HEIGHT 24
#define TH_TEXT_FIELD_CURSOR_WIDTH 2
#define TH_TEXT_FIELD_CURSOR_COLOR TH_COLOR_ACCENT

#define TH_MNEMONIC_TOP_MARGIN 4
#define TH_MNEMONIC_LEFT_MARGIN 5
#define TH_MNEMONIC_FIELD_WIDTH 140

#define TH_PROGRESS_HEIGHT 4
#define TH_PROGRESS_WIDTH 240
#define TH_PROGRESS_LEFT_MARGIN 40
#define TH_PROGRESS_VERTICAL_MARGIN 78
#define TH_PROGRESS_WARN_VERTICAL_MARGIN 115

#define TH_BRIGHTNESS_SEGMENT_WIDTH 2
#define TH_BRIGHTNESS_SEGMENT_HEIGHT 80
#define TH_BRIGHTNESS_SEGMENT_SPACING 5
#define TH_BRIGHTNESS_CHEVRON_MARGIN 8

#define TH_NAV_HINT_LEFT_X TH_SCREEN_MARGIN
#define TH_NAV_HINT_RIGHT_X (SCREEN_WIDTH - 24 - TH_SCREEN_MARGIN)
#define TH_NAV_HINT_TOP (SCREEN_HEIGHT - TH_NAV_HINT_HEIGHT + 10)
#define TH_NAV_HINT_WIDTH 40
#define TH_NAV_HINT_HEIGHT 44

#define TH_NAV_PAGER_TOP TH_NAV_HINT_TOP

#define TH_INFO_ICON_TOP_MARGIN 22
#define TH_INFO_ICON_BOTTOM_MARGIN 16
#define TH_INFO_SUBTEXT_MARGIN 4

#endif

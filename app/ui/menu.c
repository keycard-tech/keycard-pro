#include <stddef.h>

#include "common.h"
#include "dialog.h"
#include "menu.h"
#include "keypad/keypad.h"
#include "screen/screen.h"
#include "theme.h"
#include "ui_internal.h"

const menu_t menu_keycard = {
  5, {
    {MENU_CARD_NAME, NULL},
    {MENU_CHANGE_PIN, NULL},
    {MENU_CHANGE_PUK, NULL},
    {MENU_CHANGE_PAIRING, NULL},
    {MENU_RESET_CARD, NULL},
  }
};

const menu_t menu_device = {
  6, {
    {MENU_INFO, NULL},
    {MENU_DEV_AUTH, NULL},
    {MENU_DB_UPDATE, NULL},
    {MENU_BRIGHTNESS, NULL},
    {MENU_SET_OFF_TIME, NULL},
    {MENU_USB, NULL},
  }
};

const menu_t menu_connect = {
  2, {
    {MENU_CONNECT_EIP4527, NULL},
    {MENU_CONNECT_MULTICOIN, NULL},
  }
};

const menu_t menu_settings = {
  2, {
    {MENU_KEYCARD, &menu_keycard},
    {MENU_DEVICE, &menu_device},
  }
};

const menu_t menu_mainmenu = {
  5, {
    {MENU_QRCODE, NULL},
    {MENU_CONNECT, &menu_connect},
    {MENU_ADDRESSES, NULL},
    {MENU_SETTINGS, &menu_settings},
    {MENU_HELP, NULL},
  }
};

const menu_t menu_mnemonic = {
  4, {
    {MENU_MNEMO_12WORDS, NULL},
    {MENU_MNEMO_18WORDS, NULL},
    {MENU_MNEMO_24WORDS, NULL},
    {MENU_MNEMO_GENERATE, NULL},
  }
};

const menu_t menu_autooff = {
  5, {
    {MENU_OFF_3MINS, NULL},
    {MENU_OFF_5MINS, NULL},
    {MENU_OFF_10MINS, NULL},
    {MENU_OFF_30MINS, NULL},
    {MENU_OFF_NEVER, NULL},
  }
};

const menu_t menu_onoff = {
  2, {
    {MENU_ON, NULL},
    {MENU_OFF, NULL},
  }
};

const menu_t menu_keycard_blocked = {
  2, {
    {MENU_UNBLOCK_PUK, NULL},
    {MENU_RESET_CARD, NULL},
  }
};

#define MENU_MAX_DEPTH 5

void menu_render_entry(const menu_entry_t* entry, uint8_t is_selected, uint16_t yOff) {
  screen_text_ctx_t ctx;
  ctx.font = TH_FONT_MENU;

  if (is_selected) {
    ctx.bg = TH_COLOR_MENU_SELECTED_BG;
    ctx.fg = TH_COLOR_MENU_SELECTED_FG;
  } else {
    ctx.bg = TH_COLOR_MENU_BG;
    ctx.fg = TH_COLOR_MENU_FG;
  }

  ctx.x = TH_MENU_LEFT_MARGIN;
  ctx.y = yOff;

  dialog_line(&ctx, LSTR(entry->label_id), TH_MENU_HEIGHT);

  if (g_ui_cmd.params.menu.marked == entry->label_id) {
    screen_area_t mark = {
        .width = TH_MENU_MARK_WIDTH,
        .height = TH_MENU_MARK_HEIGHT,
        .x = SCREEN_WIDTH - TH_MENU_RIGHT_MARGIN - TH_MENU_MARK_WIDTH,
        .y = yOff + ((TH_MENU_HEIGHT / 2) - (TH_MENU_MARK_HEIGHT / 2))
    };

    screen_fill_area(&mark, TH_COLOR_MENU_MARK);
  }
}

enum menu_draw_mode {
  MENU_ALL,
  MENU_NEXT,
  MENU_PREV,
  MENU_NONE
};

void menu_render(const menu_t* menu, const char* title, uint8_t selected, enum menu_draw_mode mode) {
  uint16_t yOff = TH_TITLE_HEIGHT + TH_MENU_VERTICAL_MARGIN;

  int i, l;

  switch(mode) {
  case MENU_ALL:
    dialog_title(title);
    dialog_margin(TH_TITLE_HEIGHT, TH_MENU_VERTICAL_MARGIN);
    i = 0;
    l = menu->len;
    break;
  case MENU_NEXT:
    i = APP_MAX(0, selected);
    l = APP_MIN(menu->len, (selected + 2));
    yOff += (i * TH_MENU_HEIGHT);
    break;
  case MENU_PREV:
    i = APP_MAX(0, (selected - 1));
    l = APP_MIN(menu->len, (selected + 1));
    yOff += (i * TH_MENU_HEIGHT);
    break;
  case MENU_NONE:
  default:
    return;
  }

  for (; i < l; i++) {
    menu_render_entry(&menu->entries[i], i == selected, yOff);
    yOff += TH_MENU_HEIGHT;
  }

  if (mode == MENU_ALL) {
    dialog_footer(yOff);
  }
}

static uint8_t menu_scan(const menu_t* menu, const char* title, uint8_t to_find, const menu_t* menus[MENU_MAX_DEPTH], const char* titles[MENU_MAX_DEPTH], uint8_t selected[MENU_MAX_DEPTH], uint8_t depth) {
  int found = -1;
  int res = 0xff;

  for (int i = 0; i < menu->len; i++) {
    if (menu->entries[i].label_id == to_find) {
      found = i;
      res = depth;
      break;
    } else if (menu->entries[i].submenu) {
      res = menu_scan(menu->entries[i].submenu, LSTR(menu->entries[i].label_id), to_find, menus, titles, selected, (depth + 1));
      if (res != 0xff) {
        found = i;
        break;
      }
    }
  }

  if (found != -1) {
    titles[depth] = title;
    menus[depth] = menu;
    selected[depth] = found;
  }

  return res;
}

app_err_t menu_run() {
  const menu_t* menus[MENU_MAX_DEPTH];
  const char* titles[MENU_MAX_DEPTH];
  uint8_t selected[MENU_MAX_DEPTH];

  enum menu_draw_mode draw = MENU_ALL;
  uint8_t depth = menu_scan(g_ui_cmd.params.menu.menu, g_ui_cmd.params.menu.title, *g_ui_cmd.params.menu.selected, menus, titles, selected, 0);

  while(1) {
    const menu_t* menu = menus[depth];
    menu_render(menu, titles[depth], selected[depth], draw);

    switch(ui_wait_keypress(portMAX_DELAY)) {
      case KEYPAD_KEY_CANCEL:
        return ERR_CANCEL;
      case KEYPAD_KEY_BACK:
        if (depth) {
          depth--;
          draw = MENU_ALL;
        } else {
          return ERR_CANCEL;
        }
        break;
      case KEYPAD_KEY_UP:
        if (selected[depth] > 0) {
          selected[depth]--;
          draw = MENU_NEXT;
        } else {
          selected[depth] = menu->len - 1;
          draw = MENU_ALL;
        }
        break;
      case KEYPAD_KEY_DOWN:
        if (selected[depth] < (menu->len - 1)) {
          selected[depth]++;
          draw = MENU_PREV;
        } else {
          selected[depth] = 0;
          draw = MENU_ALL;
        }
        break;
      case KEYPAD_KEY_CONFIRM:
        const menu_entry_t* entry = &menu->entries[selected[depth]];
        if (entry->submenu) {
          assert(depth < (MENU_MAX_DEPTH - 1));
          menus[++depth] = entry->submenu;
          titles[depth] = LSTR(entry->label_id);
          selected[depth] = 0;
          draw = MENU_ALL;
        } else {
          *g_ui_cmd.params.menu.selected = entry->label_id;
          return ERR_OK;
        }
        break;
      default:
        draw = MENU_NONE;
        break;
    }
  }
}

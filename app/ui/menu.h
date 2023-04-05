#ifndef __MENU__
#define __MENU__

#include <stdint.h>
#include "i18n.h"

struct _menu;

typedef struct {
  i18n_str_t label_id;
  const struct _menu* submenu;
} menu_entry_t;

typedef struct _menu {
  uint8_t len;
  menu_entry_t entries[];
} menu_t;

extern const menu_t menu_mainmenu;

void menu_run(const menu_t* menu);

#endif

#ifndef _FONT_H_
#define _FONT_H_

#include <stdint.h>

typedef struct {
  uint16_t bitmapOffset;
  uint8_t width;
  uint8_t height;
  uint8_t xAdvance;
  int8_t xOffset;
  int8_t yOffset;
} glyph_t;

typedef struct {
  const uint8_t *bitmap;
  const glyph_t *glyph;
  uint32_t first;
  uint32_t last;
  uint8_t baseline;
  uint8_t yAdvance;
} font_t;

extern const font_t free_sans_18px;
extern const font_t plat_nomor_16px;
extern const font_t icons_28px;

typedef enum {
  ICON_BATTERY_LOW = 0x80,
  ICON_BATTERY_ONE = 0x81,
  ICON_BATTERY_TWO = 0x82,
  ICON_BATTERY_FULL = 0x83,
  ICON_BATTERY_CHARGING = 0x84,
  ICON_CIRCLE_EMPTY = 0x85,
  ICON_CIRCLE_FULL = 0x86,
  ICON_CIRCLE_EMPTY_LARGE = 0x87,
} icons_t;

#endif

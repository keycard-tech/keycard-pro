#include "font.h"

const uint8_t navigation_24px_bitmaps[] = {
  0x00, 0xff, 0x00, 0x03, 0xff, 0xc0, 0x0f, 0xff, 0xf0, 0x1f, 0xff, 0xf8, 
  0x3f, 0xff, 0xfc, 0x3f, 0xff, 0xfc, 0x7f, 0xff, 0xfe, 0x7f, 0xff, 0xfe, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfe, 
  0x7f, 0xff, 0xfe, 0x7f, 0xff, 0xfe, 0x3f, 0xff, 0xfc, 0x1f, 0xff, 0xf8, 
  0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0xc0, 0x00, 0x7e, 0x00, 
  0x00, 0xff, 0x00, 0x03, 0xff, 0xc0, 0x0f, 0x00, 0xf0, 0x1c, 0x00, 0x38, 
  0x38, 0x00, 0x1c, 0x30, 0x00, 0x0c, 0x60, 0x00, 0x0e, 0x60, 0x00, 0x06, 
  0xe0, 0x00, 0x07, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x03, 
  0xc0, 0x00, 0x03, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x03, 0x60, 0x00, 0x06, 
  0x60, 0x00, 0x06, 0x70, 0x00, 0x0e, 0x38, 0x00, 0x1c, 0x1c, 0x00, 0x38, 
  0x0e, 0x00, 0x70, 0x07, 0xc3, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00, 
  0x1f, 0x83, 0xfc, 0x7f, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0x7f, 0xe7, 0xfe, 0x3f, 0xc0, 0xf0, 0x01, 0xff, 0xf8, 0x07, 0xff, 0xf8, 
  0x1f, 0xff, 0xf8, 0x3f, 0xff, 0xf0, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xc7, 
  0xff, 0xff, 0x9f, 0xff, 0xff, 0x7f, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 
  0xff, 0x9f, 0xff, 0xff, 0x3f, 0xff, 0xfe, 0x3f, 0xff, 0xfc, 0x3f, 0xff, 
  0xf8, 0x7f, 0xff, 0xf0, 0x7f, 0xff, 0xe0, 0x7f, 0xff, 0xc0, 0xff, 0xff, 
  0x00, 0x7f, 0xfc, 0x01, 0xff, 0xf8, 0x07, 0xff, 0xf8, 0x1c, 0x00, 0x38, 
  0x30, 0x00, 0x30, 0xc0, 0x00, 0x63, 0x80, 0x00, 0xc6, 0x00, 0x01, 0x98, 
  0x00, 0x03, 0x70, 0x00, 0x06, 0xc0, 0x00, 0x0f, 0x00, 0x00, 0x1e, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x7c, 0x00, 0x00, 0xd8, 0x00, 0x01, 0x98, 0x00, 
  0x03, 0x38, 0x00, 0x06, 0x30, 0x00, 0x0c, 0x30, 0x00, 0x18, 0x70, 0x00, 
  0x30, 0x60, 0x00, 0x60, 0x60, 0x01, 0xc0, 0xff, 0xff, 0x00, 0x7f, 0xfc, 
  0x01, 0xfe, 0x00, 0x1f, 0xfe, 0x00, 0xff, 0xfc, 0x07, 0xff, 0xf8, 0x3f, 
  0xff, 0xf1, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xbf, 0xff, 0xfe, 0xff, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xf7, 0xff, 0xff, 0x9f, 0xff, 0xfe, 0x3f, 0xff, 0xf0, 0xff, 
  0xff, 0xc1, 0xff, 0xfe, 0x03, 0xff, 0xf0, 0x03, 0xff, 0x00, 0x03, 0xe0, 
  0x00, 
};

const glyph_t navigation_24px_glyphs[] = {
  {    0,   24,   24,   24,    0,  -24}, // 0x01
  {   72,   24,   24,   24,    0,  -24}, // 0x02
  {  144,   12,   12,   24,    6,  -18}, // 0x03
  {  162,   23,   24,   24,    0,  -24}, // 0x04
  {  231,   23,   24,   24,    0,  -24}, // 0x05
  {  300,   22,   22,   24,    1,  -23}, // 0x06
};

const font_t navigation_24px = { navigation_24px_bitmaps, navigation_24px_glyphs, 0x01, 0x06, 24, 24 };

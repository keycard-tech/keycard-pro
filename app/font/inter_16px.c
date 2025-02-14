#include "font.h"

const uint8_t inter_16px_bitmaps[] = {
  0x00, 0xfd, 0xb6, 0xdb, 0x03, 0xf0, 0xde, 0xf7, 0x39, 0x80, 0x19, 0x86, 
  0x61, 0x19, 0xff, 0x7f, 0xcc, 0xc3, 0x33, 0xfe, 0xff, 0x88, 0x82, 0x21, 
  0x98, 0x08, 0x04, 0x0f, 0x8f, 0xec, 0xb6, 0x47, 0xa0, 0xf8, 0x1f, 0x05, 
  0xb2, 0x79, 0x7f, 0xf1, 0xf0, 0x20, 0xf0, 0x67, 0x86, 0x24, 0x21, 0x22, 
  0x0f, 0x30, 0x31, 0x00, 0x11, 0xc1, 0x9e, 0x08, 0x90, 0x84, 0xcc, 0x3c, 
  0xc0, 0xe0, 0x3c, 0x3e, 0x19, 0x8c, 0xc7, 0xc1, 0x81, 0xe7, 0x9b, 0xcf, 
  0x63, 0xbf, 0xcf, 0xb0, 0xfe, 0x80, 0x33, 0x66, 0x66, 0x6e, 0xe6, 0x66, 
  0x63, 0x30, 0xcc, 0x66, 0x66, 0x67, 0x66, 0x66, 0x6c, 0xc0, 0x11, 0x2b, 
  0xf9, 0x8f, 0xf2, 0x84, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 
  0x18, 0x7b, 0x6c, 0xff, 0xc0, 0x5d, 0x80, 0x0c, 0x21, 0x86, 0x18, 0x43, 
  0x0c, 0x31, 0x86, 0x18, 0x43, 0x00, 0x1c, 0x3f, 0x18, 0xd8, 0xec, 0x5e, 
  0x4f, 0x27, 0xa3, 0xd3, 0xf1, 0x9f, 0xc7, 0xc0, 0x3f, 0xf7, 0x31, 0x8c, 
  0x63, 0x18, 0xc6, 0x30, 0x3c, 0x7e, 0xc3, 0xc3, 0x03, 0x06, 0x0e, 0x1c, 
  0x38, 0x70, 0xff, 0xff, 0x3c, 0x7e, 0xc3, 0x03, 0x07, 0x1e, 0x1f, 0x03, 
  0x03, 0xc3, 0xff, 0x3c, 0x0e, 0x07, 0x07, 0x83, 0xc3, 0x63, 0xb1, 0x99, 
  0x8c, 0xff, 0xff, 0xc1, 0x80, 0xc0, 0x7e, 0x7e, 0xc0, 0xc0, 0xdc, 0xfe, 
  0x07, 0x03, 0x03, 0xc3, 0xfe, 0x3c, 0x3c, 0x7f, 0x63, 0xc0, 0xde, 0xff, 
  0xe3, 0xc3, 0xc3, 0xe3, 0x7f, 0x3c, 0xff, 0xff, 0x06, 0x06, 0x0c, 0x0c, 
  0x18, 0x18, 0x30, 0x30, 0x60, 0xe0, 0x3c, 0x7e, 0xc3, 0xc3, 0x67, 0x3e, 
  0x7e, 0xc3, 0xc3, 0xc3, 0xff, 0x3e, 0x3c, 0x7e, 0xc3, 0xc3, 0xc3, 0xe7, 
  0x7f, 0x3b, 0x03, 0xc3, 0x7e, 0x3c, 0x5d, 0x80, 0x17, 0x60, 0xec, 0x00, 
  0x1e, 0xdb, 0x00, 0x01, 0x07, 0x1e, 0xf8, 0xe0, 0x78, 0x1e, 0x07, 0x01, 
  0xff, 0xfc, 0x00, 0x0f, 0xff, 0xc0, 0x81, 0xc1, 0xe0, 0xf0, 0x63, 0xfe, 
  0x60, 0x80, 0x79, 0xfb, 0x18, 0x30, 0xe3, 0x8e, 0x18, 0x30, 0x00, 0xc1, 
  0x80, 0x0f, 0xc0, 0xff, 0xc7, 0x03, 0x98, 0xd6, 0xcf, 0xcf, 0x33, 0x3d, 
  0x84, 0xf6, 0x13, 0xd8, 0x4f, 0x23, 0x3c, 0xff, 0xd9, 0xce, 0x70, 0x00, 
  0xff, 0x80, 0xfc, 0x00, 0x0e, 0x01, 0xe0, 0x3c, 0x0d, 0x81, 0x98, 0x33, 
  0x0c, 0x61, 0xfe, 0x3f, 0xcc, 0x19, 0x83, 0xf0, 0x30, 0xfe, 0x7f, 0xb0, 
  0xd8, 0x6c, 0x37, 0xf3, 0xfd, 0x87, 0xc1, 0xe1, 0xff, 0xdf, 0xc0, 0x1f, 
  0x1f, 0xe6, 0x1f, 0x03, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0xc0, 0xd8, 0x77, 
  0xf8, 0x78, 0xfe, 0x3f, 0xcc, 0x1b, 0x06, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 
  0xc1, 0xb0, 0x6f, 0xf3, 0xf8, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe, 
  0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe, 
  0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x1f, 0x1f, 0xe6, 0x1f, 0x03, 0xc0, 0x31, 
  0xfc, 0x7f, 0x03, 0xc0, 0xd8, 0x77, 0xf8, 0x7c, 0xc0, 0xf0, 0x3c, 0x0f, 
  0x03, 0xc0, 0xff, 0xff, 0xff, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xff, 
  0xff, 0xff, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc1, 0x83, 0xc7, 0x8f, 0xfb, 
  0xc0, 0xc1, 0xf0, 0xcc, 0x73, 0x38, 0xdc, 0x36, 0x0f, 0xc3, 0xb8, 0xc6, 
  0x30, 0xcc, 0x3b, 0x07, 0xc1, 0x83, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc1, 
  0x83, 0xff, 0xf0, 0xe0, 0x7f, 0x83, 0xfc, 0x17, 0xb1, 0xbd, 0x8d, 0xec, 
  0x6f, 0x76, 0x79, 0xb3, 0xcd, 0x9e, 0x38, 0xf1, 0xc7, 0x8c, 0x30, 0xe0, 
  0xf8, 0x3f, 0x0f, 0x63, 0xd8, 0xf3, 0x3c, 0xcf, 0x1b, 0xc7, 0xf0, 0xfc, 
  0x1f, 0x07, 0x1e, 0x0f, 0xf1, 0x87, 0x60, 0x6c, 0x0d, 0x81, 0xb0, 0x3e, 
  0x06, 0xc0, 0xcc, 0x39, 0xfe, 0x0f, 0x00, 0xfe, 0x7f, 0xb0, 0xd8, 0x7c, 
  0x3e, 0x1b, 0xfd, 0xfc, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x1e, 0x0f, 0xf1, 
  0x87, 0x60, 0x6c, 0x0d, 0x81, 0xb0, 0x3e, 0x46, 0xc6, 0xcc, 0x79, 0xfe, 
  0x0f, 0xc0, 0x0c, 0xfe, 0x7f, 0xb0, 0xd8, 0x7c, 0x3e, 0x1b, 0xfd, 0xfc, 
  0xc6, 0x63, 0xb0, 0xd8, 0x70, 0x3e, 0x3f, 0xb0, 0xd8, 0x1e, 0x03, 0xe0, 
  0x7c, 0x07, 0xc1, 0xe1, 0xff, 0xc7, 0xc0, 0xff, 0xff, 0xc6, 0x03, 0x01, 
  0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x00, 0xc0, 0xf0, 0x3c, 
  0x0f, 0x03, 0xc0, 0xf0, 0x3c, 0x0f, 0x03, 0xc1, 0xd8, 0x67, 0xf8, 0x78, 
  0xe0, 0x6c, 0x0d, 0xc3, 0x18, 0x63, 0x0c, 0x73, 0x06, 0x60, 0xcc, 0x1b, 
  0x01, 0xe0, 0x3c, 0x07, 0x00, 0xe1, 0x83, 0x61, 0xc7, 0x63, 0xc6, 0x63, 
  0xc6, 0x33, 0xc6, 0x33, 0x6c, 0x36, 0x6c, 0x36, 0x6c, 0x1e, 0x6c, 0x1e, 
  0x28, 0x1c, 0x38, 0x1c, 0x38, 0x60, 0xe6, 0x38, 0xe6, 0x0d, 0xc0, 0xf0, 
  0x1c, 0x03, 0x80, 0x78, 0x1b, 0x87, 0x31, 0xc3, 0x70, 0x70, 0xe0, 0xee, 
  0x18, 0xc7, 0x1c, 0xc1, 0xb0, 0x1e, 0x03, 0x80, 0x30, 0x06, 0x00, 0xc0, 
  0x18, 0x03, 0x00, 0xff, 0xff, 0x81, 0xc0, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 
  0x70, 0x30, 0x3f, 0xff, 0xf0, 0xff, 0x6d, 0xb6, 0xdb, 0x6d, 0xf8, 0xc1, 
  0x06, 0x18, 0x60, 0xc3, 0x0c, 0x10, 0x61, 0x86, 0x08, 0x30, 0xfd, 0xb6, 
  0xdb, 0x6d, 0xb7, 0xf8, 0x31, 0xc5, 0xb2, 0x8c, 0xff, 0xff, 0xec, 0x7d, 
  0xff, 0x18, 0x37, 0xf8, 0xf1, 0xff, 0x76, 0xc0, 0xc0, 0xc0, 0xdc, 0xff, 
  0xe3, 0xc3, 0xc3, 0xc3, 0xe3, 0xff, 0xdc, 0x3c, 0x7e, 0xc7, 0xc0, 0xc0, 
  0xc0, 0xc7, 0x7e, 0x3c, 0x03, 0x03, 0x03, 0x7b, 0xff, 0xc7, 0xc3, 0xc3, 
  0xc3, 0xc7, 0xff, 0x3b, 0x3c, 0x7e, 0xc3, 0xff, 0xff, 0xc0, 0xc3, 0x7e, 
  0x3c, 0x1c, 0xf3, 0x3f, 0xfc, 0xc3, 0x0c, 0x30, 0xc3, 0x0c, 0x3b, 0x7f, 
  0xc7, 0xc3, 0xc3, 0xc3, 0xc7, 0xff, 0x7b, 0x03, 0xfe, 0x7c, 0xc0, 0xc0, 
  0xc0, 0xdc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xf3, 0xff, 
  0xff, 0x6c, 0x36, 0xdb, 0x6d, 0xb6, 0xf0, 0xc0, 0xc0, 0xc0, 0xc7, 0xce, 
  0xdc, 0xf8, 0xf8, 0xfc, 0xcc, 0xce, 0xc7, 0xff, 0xff, 0xff, 0xdc, 0xef, 
  0xff, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x30, 
  0xdc, 0xfe, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x3c, 0x7e, 0xc7, 
  0xc3, 0xc3, 0xc3, 0xc7, 0x7e, 0x3c, 0xdc, 0xff, 0xe3, 0xc3, 0xc3, 0xc3, 
  0xe3, 0xff, 0xdc, 0xc0, 0xc0, 0xc0, 0x7b, 0xff, 0xc7, 0xc3, 0xc3, 0xc3, 
  0xc7, 0xff, 0x3b, 0x03, 0x03, 0x03, 0xdf, 0xf1, 0x8c, 0x63, 0x18, 0xc0, 
  0x7d, 0xff, 0x1f, 0x07, 0xc1, 0xf1, 0xff, 0x7c, 0x63, 0x3f, 0xf6, 0x31, 
  0x8c, 0x61, 0xce, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xff, 0x7b, 
  0xe1, 0xb1, 0xd8, 0xc6, 0x63, 0x61, 0xb0, 0x78, 0x38, 0x1c, 0x00, 0xe3, 
  0x1b, 0x38, 0xd9, 0xcc, 0xcb, 0x63, 0x5b, 0x1e, 0xd0, 0xf3, 0x83, 0x1c, 
  0x18, 0xe0, 0x63, 0xb9, 0x8d, 0x83, 0x81, 0xc0, 0xe0, 0xd8, 0xe6, 0xe3, 
  0x80, 0xe1, 0xb1, 0xd8, 0xc6, 0x63, 0x61, 0xb0, 0x78, 0x38, 0x0c, 0x0c, 
  0x1e, 0x0e, 0x00, 0xff, 0xfc, 0x30, 0xc3, 0x86, 0x18, 0x7f, 0xfe, 0x19, 
  0xcc, 0x63, 0x1b, 0x9c, 0x31, 0x8c, 0x63, 0x1c, 0x60, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xc7, 0x18, 0x42, 0x18, 0xe3, 0x31, 0x08, 0x46, 0x73, 0x00, 
  0x30, 0xbc, 0xb3, 0xd8, 0xe0, 0x12, 0x04, 0x41, 0x13, 0xff, 0x13, 0x04, 
  0x83, 0x23, 0xff, 0x22, 0x08, 0x82, 0x20, 0x0c, 0x03, 0x00, 0xc0, 0x30, 
  0x0c, 0x03, 0x08, 0xc5, 0xb6, 0x3f, 0x07, 0x80, 0xc0, 0x08, 0x03, 0x83, 
  0xf1, 0xb6, 0xcc, 0xc3, 0x00, 0xc0, 0x30, 0x0c, 0x03, 0x00, 0x00, 0x80, 
  0x30, 0x10, 0x0c, 0x02, 0x01, 0x08, 0xc3, 0x60, 0x70, 0x0c, 0x00, 0x08, 
  0xcc, 0xcc, 0x10, 0x41, 0x86, 0x18, 0x61, 0x91, 0x10, 0xc3, 0x66, 0x3c, 
  0x18, 0x10, 
};

const glyph_t inter_16px_glyphs[] = {
  {    0,    1,    1,    4,    0,    0}, // 0x20 ' '
  {    1,    3,   12,    5,    1,  -11}, // 0x21 '!'
  {    6,    5,    5,    8,    2,  -11}, // 0x22 '"'
  {   10,   10,   12,   10,    0,  -11}, // 0x23 '#'
  {   25,    9,   15,   10,    1,  -13}, // 0x24 '$'
  {   42,   13,   12,   16,    2,  -11}, // 0x25 '%'
  {   62,    9,   12,   11,    1,  -11}, // 0x26 '&'
  {   76,    2,    5,    5,    2,  -11}, // 0x27 '''
  {   78,    4,   15,    6,    1,  -12}, // 0x28 '('
  {   86,    4,   15,    6,    1,  -12}, // 0x29 ')'
  {   94,    7,    7,    9,    1,  -11}, // 0x2a '*'
  {  101,    8,    8,   11,    1,   -8}, // 0x2b '+'
  {  109,    3,    5,    5,    1,   -1}, // 0x2c ','
  {  111,    5,    2,    7,    1,   -5}, // 0x2d '-'
  {  113,    3,    3,    5,    1,   -2}, // 0x2e '.'
  {  115,    6,   14,    6,    0,  -11}, // 0x2f '/'
  {  126,    9,   12,   11,    1,  -11}, // 0x30 '0'
  {  140,    5,   12,    7,    1,  -11}, // 0x31 '1'
  {  148,    8,   12,   10,    1,  -11}, // 0x32 '2'
  {  160,    8,   12,   10,    1,  -11}, // 0x33 '3'
  {  172,    9,   12,   11,    1,  -11}, // 0x34 '4'
  {  186,    8,   12,   10,    1,  -11}, // 0x35 '5'
  {  198,    8,   12,   10,    1,  -11}, // 0x36 '6'
  {  210,    8,   12,    9,    1,  -11}, // 0x37 '7'
  {  222,    8,   12,   10,    1,  -11}, // 0x38 '8'
  {  234,    8,   12,   10,    1,  -11}, // 0x39 '9'
  {  246,    3,    9,    5,    1,   -8}, // 0x3a ':'
  {  250,    3,   11,    5,    1,   -7}, // 0x3b ';'
  {  255,    8,    9,   11,    1,   -8}, // 0x3c '<'
  {  264,    7,    6,   11,    2,   -7}, // 0x3d '='
  {  270,    7,    9,   11,    2,   -8}, // 0x3e '>'
  {  278,    7,   12,    9,    1,  -11}, // 0x3f '?'
  {  289,   14,   15,   16,    1,  -11}, // 0x40 '@'
  {  316,   11,   12,   12,    0,  -11}, // 0x41 'A'
  {  333,    9,   12,   11,    1,  -11}, // 0x42 'B'
  {  347,   10,   12,   12,    1,  -11}, // 0x43 'C'
  {  362,   10,   12,   12,    1,  -11}, // 0x44 'D'
  {  377,    8,   12,   10,    1,  -11}, // 0x45 'E'
  {  389,    8,   12,    9,    1,  -11}, // 0x46 'F'
  {  401,   10,   12,   12,    1,  -11}, // 0x47 'G'
  {  416,   10,   12,   12,    1,  -11}, // 0x48 'H'
  {  431,    2,   12,    4,    1,  -11}, // 0x49 'I'
  {  434,    7,   12,    9,    1,  -11}, // 0x4a 'J'
  {  445,   10,   12,   11,    1,  -11}, // 0x4b 'K'
  {  460,    7,   12,    9,    1,  -11}, // 0x4c 'L'
  {  471,   13,   12,   15,    1,  -11}, // 0x4d 'M'
  {  491,   10,   12,   12,    1,  -11}, // 0x4e 'N'
  {  506,   11,   12,   12,    1,  -11}, // 0x4f 'O'
  {  523,    9,   12,   10,    1,  -11}, // 0x50 'P'
  {  537,   11,   13,   12,    1,  -11}, // 0x51 'Q'
  {  555,    9,   12,   10,    1,  -11}, // 0x52 'R'
  {  569,    9,   12,   10,    1,  -11}, // 0x53 'S'
  {  583,    9,   12,   11,    1,  -11}, // 0x54 'T'
  {  597,   10,   12,   12,    1,  -11}, // 0x55 'U'
  {  612,   11,   12,   12,    0,  -11}, // 0x56 'V'
  {  629,   16,   12,   16,    0,  -11}, // 0x57 'W'
  {  653,   11,   12,   12,    0,  -11}, // 0x58 'X'
  {  670,   11,   12,   11,    0,  -11}, // 0x59 'Y'
  {  687,    9,   12,   10,    1,  -11}, // 0x5a 'Z'
  {  701,    3,   15,    6,    2,  -12}, // 0x5b '['
  {  707,    6,   14,    6,    0,  -11}, // 0x5c '\'
  {  718,    3,   15,    6,    1,  -12}, // 0x5d ']'
  {  724,    6,    5,    8,    1,  -10}, // 0x5e '^'
  {  728,    8,    2,    8,    0,    1}, // 0x5f '_'
  {  730,    3,    2,    6,    1,  -11}, // 0x60 '`'
  {  731,    7,    9,    9,    1,   -8}, // 0x61 'a'
  {  739,    8,   12,   10,    1,  -11}, // 0x62 'b'
  {  751,    8,    9,    9,    1,   -8}, // 0x63 'c'
  {  760,    8,   12,   10,    1,  -11}, // 0x64 'd'
  {  772,    8,    9,    9,    1,   -8}, // 0x65 'e'
  {  781,    6,   12,    6,    0,  -11}, // 0x66 'f'
  {  790,    8,   12,   10,    1,   -8}, // 0x67 'g'
  {  802,    8,   12,   10,    1,  -11}, // 0x68 'h'
  {  814,    2,   12,    4,    1,  -11}, // 0x69 'i'
  {  817,    3,   15,    4,    0,  -11}, // 0x6a 'j'
  {  823,    8,   12,    9,    1,  -11}, // 0x6b 'k'
  {  835,    2,   12,    4,    1,  -11}, // 0x6c 'l'
  {  838,   12,    9,   14,    1,   -8}, // 0x6d 'm'
  {  852,    8,    9,   10,    1,   -8}, // 0x6e 'n'
  {  861,    8,    9,   10,    1,   -8}, // 0x6f 'o'
  {  870,    8,   12,   10,    1,   -8}, // 0x70 'p'
  {  882,    8,   12,   10,    1,   -8}, // 0x71 'q'
  {  894,    5,    9,    6,    1,   -8}, // 0x72 'r'
  {  900,    7,    9,    9,    1,   -8}, // 0x73 's'
  {  908,    5,   11,    6,    0,  -10}, // 0x74 't'
  {  915,    8,    9,   10,    1,   -8}, // 0x75 'u'
  {  924,    9,    9,    9,    0,   -8}, // 0x76 'v'
  {  935,   13,    9,   13,    0,   -8}, // 0x77 'w'
  {  950,    9,    9,    9,    0,   -8}, // 0x78 'x'
  {  961,    9,   12,    9,    0,   -8}, // 0x79 'y'
  {  975,    7,    9,    9,    1,   -8}, // 0x7a 'z'
  {  983,    5,   15,    7,    1,  -11}, // 0x7b '{'
  {  993,    2,   20,    6,    2,  -15}, // 0x7c '|'
  {  998,    5,   15,    7,    1,  -11}, // 0x7d '}'
  { 1008,    9,    4,   11,    1,   -6}, // 0x7e '~'
  { 1013,   10,   11,   16,    3,  -10}, // 0x7f
  { 1027,   10,   11,   16,    3,   -9}, // 0x80
  { 1041,   10,   10,   16,    3,  -10}, // 0x81
  { 1054,   10,   10,   16,    4,   -9}, // 0x82
  { 1067,    5,    8,   16,    5,   -8}, // 0x83
  { 1072,    5,    8,   16,    6,   -8}, // 0x84
  { 1077,    8,    5,   16,    4,   -6}, // 0x85
};

const font_t inter_16px = { inter_16px_bitmaps, inter_16px_glyphs, 0x20, 0x85, 15, 20 };

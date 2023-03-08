#ifndef __CAMERA_REGS__
#define __CAMERA_REGS__

#define SC031GS

#define SC031GS_OUTPUT_WINDOW_START_X_H_REG 0x3212
#define SC031GS_OUTPUT_WINDOW_START_X_L_REG 0x3213
#define SC031GS_OUTPUT_WINDOW_START_Y_H_REG 0x3210
#define SC031GS_OUTPUT_WINDOW_START_Y_L_REG 0x3211
#define SC031GS_OUTPUT_WINDOW_WIDTH_H_REG 0x3208
#define SC031GS_OUTPUT_WINDOW_WIDTH_L_REG 0x3209
#define SC031GS_OUTPUT_WINDOW_HIGH_H_REG 0x320a
#define SC031GS_OUTPUT_WINDOW_HIGH_L_REG 0x320b
#define SC031GS_LED_STROBE_ENABLE_REG 0x3361

#define SC031GS_FPS_30 {0x320e, 0x0a}, {0x320f, 0xac}
#define SC031GS_FPS_120 {0x320e, 0x02},{0x320f, 0xab}

#define _CAM_I2C_ADDR 0x60

// xclk=10M
static const struct camera_regval camera_regs[] = {
  {0x0103, 0x01}, // soft reset.
  {_CAM_REG_DELAY, 10}, // delay.
  {0x0100, 0x00},
  {0x36e9, 0x80}, // ??
  {0x36f9, 0x80}, // ??
  {0x300f, 0x0f},
  {0x3018, 0x1f},
  {0x3019, 0xff},
  {0x301c, 0xb4},
  {0x301f, 0x7b}, // ??
  {0x3028, 0x82}, // ??
  {0x3200, 0x00}, // ??
  {0x3201, 0xdc}, // ??
  {0x3202, 0x00}, // ??
  {0x3203, 0x98}, // ??
  {0x3204, 0x01}, // ??
  {0x3205, 0xb3}, // ??
  {0x3206, 0x01}, // ??
  {0x3207, 0x67}, // ??
  {0x320c, 0x03},
  {0x320d, 0x6e},
  SC031GS_FPS_30,
  //{SC031GS_OUTPUT_WINDOW_WIDTH_H_REG, 0x00},
  //{SC031GS_OUTPUT_WINDOW_WIDTH_L_REG, 0xc8},
  //{SC031GS_OUTPUT_WINDOW_HIGH_H_REG, 0x00},
  //{SC031GS_OUTPUT_WINDOW_HIGH_L_REG, 0xc8},
  //{SC031GS_OUTPUT_WINDOW_START_Y_H_REG, 0x00},
  //{SC031GS_OUTPUT_WINDOW_START_Y_L_REG, 0x08},
  //{SC031GS_OUTPUT_WINDOW_START_X_H_REG, 0x00},
  //{SC031GS_OUTPUT_WINDOW_START_X_L_REG, 0x04},
  {0x3220, 0x10}, // ??
  {0x3223, 0x50}, // ??
  {0x3250, 0xf0},
  {0x3251, 0x02},
  {0x3252, 0x02},
  {0x3253, 0xa6},
  {0x3254, 0x02},
  {0x3255, 0x07},
  {0x3304, 0x48},
  {0x3306, 0x38},
  {0x3309, 0x68},
  {0x330b, 0xe0},
  {0x330c, 0x18},
  {0x330f, 0x20},
  {0x3310, 0x10},
  {0x3314, 0x3a},
  {0x3315, 0x38},
  {0x3316, 0x48},
  {0x3317, 0x20},
  {0x3329, 0x3c},
  {0x332d, 0x3c},
  {0x332f, 0x40},
  {0x3335, 0x44},
  {0x3344, 0x44},
  {0x335b, 0x80},
  {0x335f, 0x80},
  {0x3366, 0x06},
  {0x3385, 0x31},
  {0x3387, 0x51},
  {0x3389, 0x01},
  {0x33b1, 0x03},
  {0x33b2, 0x06},
  {0x3621, 0xa4},
  {0x3622, 0x05},
  {0x3624, 0x47},
  {0x3630, 0x46},
  {0x3631, 0x48},
  {0x3633, 0x52},
  {0x3635, 0x18}, // ?
  {0x3636, 0x25},
  {0x3637, 0x89},
  {0x3638, 0x0f},
  {0x3639, 0x08},
  {0x363a, 0x00},
  {0x363b, 0x48},
  {0x363c, 0x06},
  {0x363d, 0x00},
  {0x363e, 0xf8},
  {0x3640, 0x02},
  {0x3641, 0x01},
  {0x36ea, 0x3b},
  {0x36eb, 0x1a},
  {0x36ec, 0x0a},
  {0x36ed, 0x33},
  {0x36fa, 0x3a},
  {0x36fb, 0x10}, // ??
  {0x36fc, 0x01},
  {0x36fd, 0x03}, // ??
  {0x3908, 0x91},
  {0x3d08, 0x00},
  {0x3d04, 0x04}, // ??
  {0x3e01, 0xd0},
  {0x3e02, 0xff},
  {0x3e06, 0x0c},
  {0x3f04, 0x03}, // ??
  {0x3f05, 0x4b}, // ??
  {0x4500, 0x59},
  {0x4501, 0xc4},
  {0x4809, 0x01}, // ??
  {0x4837, 0x39}, // ??
  {0x5011, 0x00},
  {0x36e9, 0x04},
  {0x36f9, 0x04},
  {0x0100, 0x01},

  //delay 10ms
  {_CAM_REG_DELAY, 0X0a},
  {0x4418, 0x08},
  {0x4419, 0x80},
  {0x363d, 0x10},
  {0x3630, 0x48},

  // [gain<4]
  {0x3317, 0x0d},
  {0x3314, 0x70},

  // [gain>=4]
  {0x3314, 0x68},
  {0x3317, 0x0e},
  {_CAM_REG_NULL, 0x00},
};
#else
#error This file must be only imported once.
#endif
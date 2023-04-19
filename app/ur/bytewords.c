#include "bytewords.h"
#include "hal.h"
#include "common.h"
#include "crypto/crc32.h"
#include <ctype.h>

const static uint8_t BW_DECODE_LUT[] = {
    0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x09, 0x07, 0x00, 0x00, 0x00, 0x03, 0x08, 0x00, 0x0e, 0x14, 0x00, 0x0b, 0x10, 0x00,
    0x12, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0d, 0x00, 0x00,
    0x13, 0x00, 0x11, 0x15, 0x1d, 0x00, 0x00, 0x00, 0x1c, 0x19, 0x00, 0x17, 0x00, 0x00, 0x1e, 0x21,
    0x16, 0x23, 0x00, 0x22, 0x00, 0x00, 0x18, 0x1f, 0x00, 0x00, 0x1b, 0x20, 0x1a, 0x00, 0x25, 0x00,
    0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x27, 0x00, 0x24, 0x2f, 0x2e, 0x2b, 0x00, 0x2d, 0x00, 0x2a,
    0x26, 0x29, 0x00, 0x00, 0x2c, 0x00, 0x30, 0x00, 0x00, 0x00, 0x35, 0x00, 0x34, 0x00, 0x00, 0x31,
    0x00, 0x00, 0x00, 0x00, 0x37, 0x36, 0x33, 0x00, 0x00, 0x00, 0x39, 0x38, 0x00, 0x00, 0x00, 0x00,
    0x32, 0x00, 0x00, 0x00, 0x00, 0x48, 0x45, 0x00, 0x46, 0x3f, 0x00, 0x00, 0x00, 0x47, 0x3e, 0x3c,
    0x00, 0x41, 0x00, 0x3b, 0x3d, 0x3a, 0x00, 0x00, 0x42, 0x43, 0x44, 0x40, 0x49, 0x00, 0x00, 0x50,
    0x4a, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x4e, 0x52, 0x00, 0x55, 0x00, 0x00, 0x4b, 0x4c, 0x4d,
    0x53, 0x00, 0x4f, 0x00, 0x51, 0x00, 0x00, 0x00, 0x00, 0x58, 0x5f, 0x56, 0x57, 0x5c, 0x00, 0x00,
    0x59, 0x5d, 0x00, 0x60, 0x00, 0x5b, 0x00, 0x00, 0x61, 0x5a, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x00,
    0x63, 0x00, 0x00, 0x62, 0x64, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x6a, 0x69, 0x67, 0x00,
    0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6b, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x73, 0x6f, 0x00, 0x6d, 0x70, 0x72, 0x00, 0x00, 0x71, 0x6e, 0x00, 0x00,
    0x00, 0x00, 0x74, 0x6c, 0x00, 0x7e, 0x00, 0x00, 0x7c, 0x00, 0x7b, 0x00, 0x7d, 0x00, 0x79, 0x00,
    0x00, 0x7a, 0x76, 0x75, 0x00, 0x00, 0x78, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7f,
    0x00, 0x89, 0x8a, 0x82, 0x8d, 0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x86, 0x88, 0x85, 0x00, 0x84,
    0x83, 0x87, 0x8b, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x95, 0x91, 0x00, 0x00, 0x90,
    0x00, 0x00, 0x98, 0x00, 0x00, 0x8e, 0x92, 0x00, 0x00, 0x00, 0x97, 0x96, 0x93, 0x00, 0x94, 0x00,
    0x8f, 0x00, 0x00, 0xa0, 0x00, 0x9b, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x00, 0x9e,
    0x00, 0x00, 0x00, 0x00, 0x9c, 0x9d, 0x00, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xa2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa6, 0x00, 0xa5, 0x00, 0x00, 0x00, 0x00, 0xa7, 0xa3,
    0x00, 0x00, 0x00, 0xa4, 0xa1, 0x00, 0xb1, 0x00, 0x00, 0xa8, 0xaf, 0xb0, 0x00, 0x00, 0x00, 0x00,
    0xaa, 0xae, 0xad, 0x00, 0x00, 0x00, 0x00, 0xb2, 0xac, 0xa9, 0x00, 0x00, 0x00, 0x00, 0xab, 0x00,
    0x00, 0x00, 0x00, 0xb3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb4, 0x00, 0x00, 0x00, 0xba, 0xb5, 0xbc,
    0x00, 0xb9, 0x00, 0x00, 0xbb, 0xb7, 0x00, 0xbe, 0xb8, 0xb6, 0x00, 0x00, 0xbf, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0xbd, 0x00, 0xc2, 0xcb, 0x00, 0x00, 0xc1, 0xcc, 0xca, 0x00, 0x00, 0x00, 0xc5, 0x00,
    0x00, 0xcd, 0xc9, 0xc8, 0x00, 0xc3, 0xc4, 0xc7, 0x00, 0x00, 0xc6, 0x00, 0x00, 0x00, 0xd9, 0xd6,
    0x00, 0xd2, 0xd3, 0x00, 0x00, 0x00, 0xd0, 0x00, 0xcf, 0xd5, 0x00, 0xda, 0xce, 0xd8, 0x00, 0x00,
    0xd7, 0xd1, 0x00, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdc, 0x00, 0x00, 0xdf, 0x00, 0xdd, 0x00, 0x00, 0x00, 0x00,
    0xdb, 0x00, 0xe6, 0x00, 0x00, 0xe7, 0xe4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0x00, 0x00,
    0xe2, 0x00, 0x00, 0x00, 0xe8, 0xe0, 0x00, 0x00, 0xe5, 0x00, 0xe1, 0x00, 0x00, 0x00, 0x00, 0xea,
    0xed, 0xf3, 0x00, 0x00, 0x00, 0x00, 0xf4, 0xe9, 0xeb, 0xf1, 0x00, 0xec, 0x00, 0x00, 0xef, 0xf0,
    0x00, 0x00, 0x00, 0x00, 0xee, 0xf2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf5, 0xf7, 0x00, 0xf6, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfd, 0x00, 0xfe, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xfb, 0x00, 0x00, 0x00, 0xfa, 0xfc, 0x00, 0x00,
};

const static uint16_t BW_ENCODE_LUT[] = {
    0x4541, 0x4441, 0x4f41, 0x5841, 0x4141, 0x4841, 0x4d41, 0x5441,
    0x5941, 0x5341, 0x4b42, 0x4442, 0x4e42, 0x5442, 0x4142, 0x5342,
    0x4542, 0x5942, 0x4742, 0x5742, 0x4242, 0x5a42, 0x4d43, 0x4843,
    0x5343, 0x4643, 0x5943, 0x5743, 0x4543, 0x4143, 0x4b43, 0x5443,
    0x5843, 0x4c43, 0x5043, 0x4e43, 0x4b44, 0x4144, 0x5344, 0x4944,
    0x4544, 0x5444, 0x5244, 0x4e44, 0x5744, 0x5044, 0x4d44, 0x4c44,
    0x5944, 0x4845, 0x5945, 0x4f45, 0x4545, 0x4345, 0x4e45, 0x4d45,
    0x5445, 0x5345, 0x5446, 0x5246, 0x4e46, 0x5346, 0x4d46, 0x4846,
    0x5a46, 0x5046, 0x5746, 0x5846, 0x5946, 0x4546, 0x4746, 0x4c46,
    0x4446, 0x4147, 0x4547, 0x5247, 0x5347, 0x5447, 0x4c47, 0x5747,
    0x4447, 0x5947, 0x4d47, 0x5547, 0x4847, 0x4f47, 0x4648, 0x4748,
    0x4448, 0x4b48, 0x5448, 0x5048, 0x4848, 0x4c48, 0x5948, 0x4548,
    0x4e48, 0x5348, 0x4449, 0x4149, 0x4549, 0x4849, 0x5949, 0x4f49,
    0x5349, 0x4e49, 0x4d49, 0x454a, 0x5a4a, 0x4e4a, 0x544a, 0x4c4a,
    0x4f4a, 0x534a, 0x504a, 0x4b4a, 0x594a, 0x504b, 0x4f4b, 0x544b,
    0x534b, 0x4b4b, 0x4e4b, 0x474b, 0x454b, 0x494b, 0x424b, 0x424c,
    0x414c, 0x594c, 0x464c, 0x534c, 0x524c, 0x504c, 0x4e4c, 0x544c,
    0x4f4c, 0x444c, 0x454c, 0x554c, 0x4b4c, 0x474c, 0x4e4d, 0x594d,
    0x484d, 0x454d, 0x4f4d, 0x554d, 0x574d, 0x444d, 0x544d, 0x534d,
    0x4b4d, 0x4c4e, 0x594e, 0x444e, 0x534e, 0x544e, 0x4e4e, 0x454e,
    0x424e, 0x594f, 0x454f, 0x544f, 0x584f, 0x4e4f, 0x4c4f, 0x534f,
    0x4450, 0x5450, 0x4b50, 0x5950, 0x5350, 0x4d50, 0x4c50, 0x4550,
    0x4650, 0x4150, 0x5250, 0x4451, 0x5a51, 0x4552, 0x5052, 0x4c52,
    0x4f52, 0x4852, 0x4452, 0x4b52, 0x4652, 0x5952, 0x4e52, 0x5352,
    0x5452, 0x4553, 0x4153, 0x5253, 0x5353, 0x4b53, 0x5753, 0x5453,
    0x5053, 0x4f53, 0x4753, 0x4253, 0x4653, 0x4e53, 0x4f54, 0x4b54,
    0x4954, 0x5454, 0x4454, 0x4554, 0x5954, 0x4c54, 0x4254, 0x5354,
    0x5054, 0x4154, 0x4e54, 0x5955, 0x4f55, 0x5455, 0x4555, 0x5255,
    0x5456, 0x5956, 0x4f56, 0x4c56, 0x4556, 0x5756, 0x4156, 0x4456,
    0x5356, 0x4c57, 0x4457, 0x4d57, 0x5057, 0x4557, 0x5957, 0x5357,
    0x5457, 0x4e57, 0x5a57, 0x4657, 0x4b57, 0x4b59, 0x4e59, 0x4c59,
    0x4159, 0x5459, 0x535a, 0x4f5a, 0x545a, 0x435a, 0x455a, 0x4d5a,
};

static inline uint16_t bytewords_decode_hash(uint8_t i, uint8_t j) {
  i = toupper(i) - 'A';
  j = toupper(j) - 'A';
  return (i*26) + j;
}


size_t bytewords_decode(const uint8_t* in, size_t in_len, uint8_t* out, size_t max_out) {
  in_len /= 2;
  size_t outlen = in_len - 4;

  if (outlen > max_out) {
    return 0;
  }

  crc32_ctx_t crc32;
  crc32_init(&crc32);

  while(in_len-- > 4) {
    *out = BW_DECODE_LUT[bytewords_decode_hash(in[0], in[1])];
    crc32_update_one(&crc32, *(out++));
    in += 2;
  }

  uint32_t checksum;
  crc32_finish(&crc32, &checksum);

  uint32_t expectedChecksum;
  uint8_t* _chk = (uint8_t *)&expectedChecksum;

  while(in_len-- < SIZE_MAX) {
    *(_chk++) = BW_DECODE_LUT[bytewords_decode_hash(in[0], in[1])];
    in += 2;
  }

  return checksum == rev32(expectedChecksum) ? outlen : 0;
}

size_t bytewords_encode(const uint8_t* in, size_t in_len, uint8_t* out, size_t max_out) {
  size_t outlen = (in_len + 4) * 2;

  if (max_out < outlen) {
    return 0;
  }

  crc32_ctx_t crc32;
  crc32_init(&crc32);

  uint16_t* _out = (uint16_t*) out;
  while(in_len--) {
    crc32_update_one(&crc32, *in);
    *(_out++) = BW_ENCODE_LUT[*(in++)];
  }

  uint32_t checksum;
  crc32_finish(&crc32, &checksum);

  *(_out++) = checksum & 0xff;
  *(_out++) = (checksum >> 8) & 0xff;
  *(_out++) = (checksum >> 16) & 0xff;
  *(_out++) = (checksum >> 24);

  return outlen;
}

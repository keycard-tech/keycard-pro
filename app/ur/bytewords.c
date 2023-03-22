#include "bytewords.h"
#include "hal.h"
#include "crypto/util.h"
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
    0x6561, 0x6461, 0x6f61, 0x7861, 0x6161, 0x6861, 0x6d61, 0x7461,
    0x7961, 0x7361, 0x6b62, 0x6462, 0x6e62, 0x7462, 0x6162, 0x7362,
    0x6562, 0x7962, 0x6762, 0x7762, 0x6262, 0x7a62, 0x6d63, 0x6863,
    0x7363, 0x6663, 0x7963, 0x7763, 0x6563, 0x6163, 0x6b63, 0x7463,
    0x7863, 0x6c63, 0x7063, 0x6e63, 0x6b64, 0x6164, 0x7364, 0x6964,
    0x6564, 0x7464, 0x7264, 0x6e64, 0x7764, 0x7064, 0x6d64, 0x6c64,
    0x7964, 0x6865, 0x7965, 0x6f65, 0x6565, 0x6365, 0x6e65, 0x6d65,
    0x7465, 0x7365, 0x7466, 0x7266, 0x6e66, 0x7366, 0x6d66, 0x6866,
    0x7a66, 0x7066, 0x7766, 0x7866, 0x7966, 0x6566, 0x6766, 0x6c66,
    0x6466, 0x6167, 0x6567, 0x7267, 0x7367, 0x7467, 0x6c67, 0x7767,
    0x6467, 0x7967, 0x6d67, 0x7567, 0x6867, 0x6f67, 0x6668, 0x6768,
    0x6468, 0x6b68, 0x7468, 0x7068, 0x6868, 0x6c68, 0x7968, 0x6568,
    0x6e68, 0x7368, 0x6469, 0x6169, 0x6569, 0x6869, 0x7969, 0x6f69,
    0x7369, 0x6e69, 0x6d69, 0x656a, 0x7a6a, 0x6e6a, 0x746a, 0x6c6a,
    0x6f6a, 0x736a, 0x706a, 0x6b6a, 0x796a, 0x706b, 0x6f6b, 0x746b,
    0x736b, 0x6b6b, 0x6e6b, 0x676b, 0x656b, 0x696b, 0x626b, 0x626c,
    0x616c, 0x796c, 0x666c, 0x736c, 0x726c, 0x706c, 0x6e6c, 0x746c,
    0x6f6c, 0x646c, 0x656c, 0x756c, 0x6b6c, 0x676c, 0x6e6d, 0x796d,
    0x686d, 0x656d, 0x6f6d, 0x756d, 0x776d, 0x646d, 0x746d, 0x736d,
    0x6b6d, 0x6c6e, 0x796e, 0x646e, 0x736e, 0x746e, 0x6e6e, 0x656e,
    0x626e, 0x796f, 0x656f, 0x746f, 0x786f, 0x6e6f, 0x6c6f, 0x736f,
    0x6470, 0x7470, 0x6b70, 0x7970, 0x7370, 0x6d70, 0x6c70, 0x6570,
    0x6670, 0x6170, 0x7270, 0x6471, 0x7a71, 0x6572, 0x7072, 0x6c72,
    0x6f72, 0x6872, 0x6472, 0x6b72, 0x6672, 0x7972, 0x6e72, 0x7372,
    0x7472, 0x6573, 0x6173, 0x7273, 0x7373, 0x6b73, 0x7773, 0x7473,
    0x7073, 0x6f73, 0x6773, 0x6273, 0x6673, 0x6e73, 0x6f74, 0x6b74,
    0x6974, 0x7474, 0x6474, 0x6574, 0x7974, 0x6c74, 0x6274, 0x7374,
    0x7074, 0x6174, 0x6e74, 0x7975, 0x6f75, 0x7475, 0x6575, 0x7275,
    0x7476, 0x7976, 0x6f76, 0x6c76, 0x6576, 0x7776, 0x6176, 0x6476,
    0x7376, 0x6c77, 0x6477, 0x6d77, 0x7077, 0x6577, 0x7977, 0x7377,
    0x7477, 0x6e77, 0x7a77, 0x6677, 0x6b77, 0x6b79, 0x6e79, 0x6c79,
    0x6179, 0x7479, 0x737a, 0x6f7a, 0x747a, 0x637a, 0x657a, 0x6d7a,
};

static inline uint16_t bytewords_decode_hash(uint8_t i, uint8_t j) {
  i = tolower(i) - 'a';
  j = tolower(j) - 'a';
  return (i*26) + j;
}


size_t bytewords_decode(uint8_t* in, size_t in_len, uint8_t* out, size_t max_out) {
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

size_t bytewords_encode(uint8_t* in, size_t in_len, uint8_t* out, size_t max_out) {
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
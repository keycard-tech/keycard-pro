#include <string.h>
#include "aes.h"

#define AES_128_KEYROUND 10
#define AES_192_KEYROUND 12
#define AES_256_KEYROUND 14

#ifdef CM7
#include "aes/CM7.h"
#define _AES(x) CM7_1T_AES_##x
#elif defined CM4F
#include "aes/CM3.h"
#define _AES(x) CM3_1T_AES_##x
#elif defined CM33
#include "aes/CM3.h"
#define _AES(x) CM3_1T_AES_##x
#else
#error Unsupported architecture
#endif

const static uint8_t cmac_iv[AES_IV_SIZE] __attribute__((aligned(4))) = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

uint8_t aes_encrypt_cbc(const uint8_t* key, const uint8_t* iv, const uint8_t* data, uint32_t len, uint8_t* out) {
  uint8_t round_key[(AES_256_KEYROUND+1)*16] __attribute__((aligned(4)));
  _AES(256_keyschedule_enc(round_key, key));

  uint32_t* data_in_p = (uint32_t*) data;
  uint32_t* data_out_p = (uint32_t*) out;
  uint32_t* iv_p = (uint32_t*) iv;
  uint32_t blocks_cnt = len / 16;

  for(uint32_t i = 0; i < blocks_cnt ; i++) {
    data_out_p[0] = data_in_p[0] ^ iv_p[0];
    data_out_p[1] = data_in_p[1] ^ iv_p[1];
    data_out_p[2] = data_in_p[2] ^ iv_p[2];
    data_out_p[3] = data_in_p[3] ^ iv_p[3];

    _AES(encrypt(round_key, (uint8_t *) data_out_p, (uint8_t*) data_out_p, AES_256_KEYROUND));

    iv_p = data_out_p;
    data_out_p += 4;
    data_in_p += 4;
  }
  
  return 1;
}

uint8_t aes_decrypt_cbc(const uint8_t* key, const uint8_t* iv, const uint8_t* data, uint32_t len, uint8_t* out) {
  uint8_t round_key[(AES_256_KEYROUND+1)*16] __attribute__((aligned(4)));
  uint32_t iv_tmp[4] __attribute__((aligned(4)));

  _AES(256_keyschedule_enc(round_key, key));
  _AES(keyschedule_dec(round_key, AES_256_KEYROUND));

  uint32_t* data_out_p = (uint32_t*) out;
  uint32_t blocks_cnt = len / 16;

  memcpy(iv_tmp, iv, 16);
  while(blocks_cnt--) {
    _AES(decrypt(round_key, (uint8_t *) data, (uint8_t *) data_out_p, AES_256_KEYROUND));

    data_out_p[0] ^= iv_tmp[0];
    data_out_p[1] ^= iv_tmp[1];
    data_out_p[2] ^= iv_tmp[2];
    data_out_p[3] ^= iv_tmp[3];

    memcpy(iv_tmp, data, 16);
    data_out_p += 4;
    data += 16;
  }

  return 1;
}

uint8_t aes_cmac(const uint8_t* key, const uint8_t* data, uint32_t len, uint8_t* out) {
  uint8_t round_key[(AES_256_KEYROUND+1)*16] __attribute__((aligned(4)));
  _AES(256_keyschedule_enc(round_key, key));

  uint32_t* data_in_p = (uint32_t*) data;
  uint32_t* data_out_p = (uint32_t*) out;
  uint32_t* iv_p = (uint32_t*) cmac_iv;
  uint32_t blocks_cnt = len / 16;

  for(uint32_t i = 0; i < blocks_cnt ; i++) {
    data_out_p[0] = data_in_p[0] ^ iv_p[0];
    data_out_p[1] = data_in_p[1] ^ iv_p[1];
    data_out_p[2] = data_in_p[2] ^ iv_p[2];
    data_out_p[3] = data_in_p[3] ^ iv_p[3];

    _AES(encrypt(round_key, (uint8_t *) data_out_p, (uint8_t*) data_out_p, AES_256_KEYROUND));

    iv_p = data_out_p;
    data_in_p += 4;
  }

  return 1;
}

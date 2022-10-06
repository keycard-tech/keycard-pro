#ifndef __KEYCARD_CMDSET_H
#define __KEYCARD_CMDSET_H

#include "keycard.h"

uint8_t Keycard_CMD_Select(Keycard* kc, const uint8_t* aid, uint32_t len);
uint8_t Keycard_CMD_Pair(Keycard* kc, uint8_t step, uint8_t* data);
uint16_t Keycard_CMD_AutoPair(Keycard* kc, const uint8_t* psk, Pairing* pairing);
uint8_t Keycard_CMD_VerifyPIN(Keycard* kc, uint8_t* pin);
uint8_t Keycard_CMD_UnblockPIN(Keycard* kc, uint8_t* pin, uint8_t* puk);
uint8_t Keycard_CMD_GetStatus(Keycard* kc);
uint16_t Keycard_CMD_Init(Keycard* kc, uint8_t* sc_pub, uint8_t* pin, uint8_t* puk, uint8_t* psk);

#endif
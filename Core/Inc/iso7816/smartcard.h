#ifndef __SMARTCARD_H
#define __SMARTCARD_H

#include "main.h"
#include "atr_types.h"

typedef enum {
  SC_NOT_PRESENT,
  SC_OFF,
  SC_READY
} SmartCardState;

typedef enum {
  SC_T0,
  SC_T1
} SmartCardProtocol;

typedef struct {
  SMARTCARD_HandleTypeDef* dev;
  SmartCardState state;
  ATR atr;
  uint32_t etu;
} SmartCard;

void SmartCard_Init(SmartCard* sc, SMARTCARD_HandleTypeDef* dev);
void SmartCard_Activate(SmartCard* sc);
void SmartCard_Deactivate(SmartCard* sc);
void SmartCard_In(SmartCard* sc);
void SmartCard_Out(SmartCard* sc);

#endif
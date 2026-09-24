#ifndef DTC_STORE_H
#define DTC_STORE_H
#include <stdint.h>
#define DTC_CAPACITY 16U
void DTC_Init(void);
int DTC_Add(uint16_t code);
uint8_t DTC_Count(void);
uint16_t DTC_Get(uint8_t index);
void DTC_ClearAll(void);
#endif

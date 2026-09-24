#include "dtc_store.h"
static uint16_t dtcs[DTC_CAPACITY];
static uint8_t count;
void DTC_Init(void) { count = 0U; }
int DTC_Add(uint16_t code)
{
    if (code == 0U || count >= DTC_CAPACITY) return -1;
    dtcs[count++] = code;
    /* Replace with STM32 Flash persistence during hardware integration. */
    return 0;
}
uint8_t DTC_Count(void) { return count; }
uint16_t DTC_Get(uint8_t index) { return (index < count) ? dtcs[index] : 0U; }
void DTC_ClearAll(void) { count = 0U; }

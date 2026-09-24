#ifndef CAN_IF_H
#define CAN_IF_H
#include <stdint.h>
#define DIAG_REQUEST_ID 0x7E0U
#define DIAG_RESPONSE_ID 0x7E8U
typedef struct { uint32_t id; uint8_t dlc; uint8_t data[8]; } CanFrame_t;
void CAN_IF_Init(void);
int CAN_IF_Send(const CanFrame_t *frame);
void CAN_IF_OnReceive(const CanFrame_t *frame);
#endif

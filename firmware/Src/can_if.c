#include "can_if.h"
void CAN_IF_Init(void)
{
    /* Connect to STM32 HAL CAN/FDCAN initialization in the board project. */
}
int CAN_IF_Send(const CanFrame_t *frame)
{
    if (frame == 0) return -1;
    /* HAL_CAN_AddTxMessage() or HAL_FDCAN_AddMessageToTxFifoQ() goes here. */
    return 0;
}
void CAN_IF_OnReceive(const CanFrame_t *frame)
{
    (void)frame;
    /* Route the RX callback into the diagnostic service layer. */
}

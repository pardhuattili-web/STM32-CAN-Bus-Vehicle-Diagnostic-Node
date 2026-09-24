#include "diag_service.h"
#include "dtc_store.h"
static void send_negative(uint8_t service, uint8_t code)
{
    CanFrame_t tx = {0};
    tx.id = DIAG_RESPONSE_ID;
    tx.dlc = 3U;
    tx.data[0] = 0x7FU;
    tx.data[1] = service;
    tx.data[2] = code;
    (void)CAN_IF_Send(&tx);
}
void DIAG_ProcessRequest(const CanFrame_t *request)
{
    if (request == 0 || request->id != DIAG_REQUEST_ID || request->dlc < 2U) return;
    const uint8_t service = request->data[1];
    CanFrame_t tx = {0};
    tx.id = DIAG_RESPONSE_ID;
    tx.dlc = 2U;
    switch (service)
    {
    case 0x10U:
        if (request->dlc < 3U) { send_negative(service, 0x13U); return; }
        tx.data[0] = 0x50U; tx.data[1] = request->data[2];
        break;
    case 0x22U:
        if (request->dlc < 4U) { send_negative(service, 0x13U); return; }
        tx.data[0] = 0x62U;
        tx.data[1] = request->data[2];
        tx.data[2] = request->data[3];
        tx.dlc = 3U;
        /* DID-specific payload encoding belongs here. */
        break;
    case 0x19U:
        tx.data[0] = 0x59U;
        tx.data[1] = DTC_Count();
        break;
    case 0x14U:
        DTC_ClearAll();
        tx.data[0] = 0x54U;
        break;
    default:
        send_negative(service, 0x11U);
        return;
    }
    (void)CAN_IF_Send(&tx);
}

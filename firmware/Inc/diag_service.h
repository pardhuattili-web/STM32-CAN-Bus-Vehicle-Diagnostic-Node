#ifndef DIAG_SERVICE_H
#define DIAG_SERVICE_H
#include "can_if.h"
void DIAG_ProcessRequest(const CanFrame_t *request);
#endif

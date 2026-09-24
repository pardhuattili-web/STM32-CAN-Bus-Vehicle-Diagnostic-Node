#ifndef VEHICLE_DATA_H
#define VEHICLE_DATA_H
#include <stdint.h>
uint16_t VEHICLE_GetBatteryVoltage_dV(void);
int16_t VEHICLE_GetBatteryCurrent_dA(void);
int16_t VEHICLE_GetMotorTemperature_C(void);
uint16_t VEHICLE_GetVehicleSpeed_dKph(void);
uint8_t VEHICLE_GetSoc_pct(void);
#endif

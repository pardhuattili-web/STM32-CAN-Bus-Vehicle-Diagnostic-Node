#include "vehicle_data.h"
static uint16_t battery_voltage_dV = 370U;
static int16_t battery_current_dA = 25;
static int16_t motor_temp_C = 42;
static uint16_t vehicle_speed_dKph = 0U;
static uint8_t soc_pct = 78U;
uint16_t VEHICLE_GetBatteryVoltage_dV(void) { return battery_voltage_dV; }
int16_t VEHICLE_GetBatteryCurrent_dA(void) { return battery_current_dA; }
int16_t VEHICLE_GetMotorTemperature_C(void) { return motor_temp_C; }
uint16_t VEHICLE_GetVehicleSpeed_dKph(void) { return vehicle_speed_dKph; }
uint8_t VEHICLE_GetSoc_pct(void) { return soc_pct; }

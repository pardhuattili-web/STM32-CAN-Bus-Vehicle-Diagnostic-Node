# Firmware Architecture

## Data Flow

```
CAN RX
  |
  v
CAN Interface
  |
  v
Diagnostic Parser
  |
  +--------+--------+
  |                 |
  v                 v
Vehicle Data      DTC Store
  |                 |
  +--------+--------+
           |
           v
     Response Builder
           |
           v
          CAN TX
```

## Module Responsibilities

### can_if
Initializes CAN/FDCAN, configures filters, receives frames, and transmits responses.

### diag_service
Validates request length, decodes service identifiers, dispatches service handlers, and builds responses.

### vehicle_data
Owns application measurements and provides getters with defined scaling. It can later be connected to ADC, I2C, SPI, or network data.

### dtc_store
Maintains active DTCs and provides read/clear operations. The abstraction can later be backed by STM32 Flash.

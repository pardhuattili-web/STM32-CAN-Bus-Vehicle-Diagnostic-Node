# STM32 CAN Bus Vehicle Diagnostic Node

> **Automotive embedded systems project | STM32 + Embedded C + CAN**

A modular STM32 firmware project that models a vehicle ECU diagnostic node communicating over a Controller Area Network (CAN). The node receives CAN diagnostic requests, validates and parses them, returns structured responses, reports simulated vehicle parameters, and maintains diagnostic trouble codes (DTCs).

This repository is designed as a **portfolio-ready automotive embedded project** and can be extended toward UDS/ISO 14229 and ISO-TP implementations.

## Project Overview

**CAN Request → CAN Filter → Diagnostic Parser → Service Handler → ECU Data/DTC Store → CAN Response**

The implementation is intentionally layered so that the CAN driver, diagnostic services, application data, and non-volatile DTC storage can be tested independently.

## Objectives

- Implement robust CAN frame transmit/receive handling.
- Filter diagnostic traffic using CAN identifiers.
- Parse request payloads and dispatch diagnostic services.
- Expose simulated battery, motor/inverter temperature, and system-status data.
- Detect and store basic diagnostic trouble codes.
- Persist DTC records in STM32 Flash.
- Provide a UART debug console for development and testing.
- Keep the architecture ready for future ISO-TP/UDS expansion.

## Target Platform

| Item | Selection |
|---|---|
| MCU | STM32 family |
| Language | Embedded C |
| CAN | CAN / FDCAN peripheral, depending on STM32 target |
| Debug | SWD + UART |
| Storage | Internal Flash |
| Optional RTOS | FreeRTOS |
| Test setup | 2-node CAN bus, CAN analyzer, or simulator |

> Pin names, CAN instance names, clock settings, and HAL calls should be adapted to the exact STM32 board selected in STM32CubeIDE.

## Repository Structure

```text
STM32-CAN-Bus-Vehicle-Diagnostic-Node/
├── README.md
├── docs/
│   ├── architecture.md
│   ├── can_protocol.md
│   └── test_plan.md
└── firmware/
    ├── Inc/
    │   ├── can_if.h
    │   ├── diag_service.h
    │   ├── vehicle_data.h
    │   └── dtc_store.h
    └── Src/
        ├── can_if.c
        ├── diag_service.c
        ├── vehicle_data.c
        └── dtc_store.c
```

## Diagnostic Model

The project uses a compact application-level diagnostic protocol so the firmware can be tested without requiring a full UDS stack.

### Request CAN ID
`0x7E0`

### Response CAN ID
`0x7E8`

### Example Services

| Service | Request | Response | Purpose |
|---|---|---|---|
| ECU status | `02 10 01` | `02 50 01` | Read ECU status |
| Read data | `03 22 XX YY` | `XX YY DATA...` | Read a vehicle parameter |
| Read DTCs | `02 19 02` | DTC payload | Read stored DTCs |
| Clear DTCs | `02 14 FF` | Positive/negative response | Clear diagnostic records |

The exact payload layout is documented in [docs/can_protocol.md](docs/can_protocol.md).

## Supported Vehicle Data

The reference application exposes simulated parameters such as:

- Battery voltage
- Battery current
- Motor/inverter temperature
- Vehicle speed
- State of charge
- ECU health/status

These values can later be replaced with real ADC, sensor, or network data.

## DTC Handling

```text
Fault detected
    ↓
DTC created
    ↓
DTC stored
    ↓
DTC reported over CAN
    ↓
Fault cleared / diagnostic clear request
```

Example DTCs:

| DTC | Meaning |
|---|---|
| `0x0101` | Battery undervoltage |
| `0x0102` | Battery overvoltage |
| `0x0201` | Motor over-temperature |
| `0x0301` | CAN communication timeout |

## Firmware Architecture

The software is divided into four logical layers:

1. **CAN Interface** — peripheral initialization, filters, RX callbacks, and transmission.
2. **Diagnostic Service Layer** — request parsing and service dispatch.
3. **Vehicle Data Layer** — application parameters and simulated measurements.
4. **DTC Storage Layer** — diagnostic record management and persistence abstraction.

## Development Roadmap

### Phase 1 — Core CAN
- [x] Repository structure
- [x] Protocol definition
- [ ] Configure CAN/FDCAN
- [ ] RX/TX driver
- [ ] Message filtering

### Phase 2 — Diagnostics
- [ ] Diagnostic parser
- [ ] ECU status service
- [ ] Read-data service
- [ ] DTC read service
- [ ] DTC clear service

### Phase 3 — Persistence & Monitoring
- [ ] Flash DTC storage
- [ ] Timeout/error handling
- [ ] UART debug console
- [ ] Periodic telemetry

### Phase 4 — Automotive Extension
- [ ] ISO-TP transport
- [ ] UDS services
- [ ] Session control
- [ ] Security access
- [ ] ECU reprogramming support

## Validation Plan

The project should be validated using one of the following:

- Two STM32 boards connected through CAN transceivers.
- A CAN-to-USB interface and PC CAN analyzer.
- A CAN simulation environment.

Record CAN traces, test cases, and screenshots in the repository before claiming hardware validation.

## Portfolio Notes

This project demonstrates:

- Embedded C
- STM32 peripheral development
- CAN communication
- Interrupt-driven communication
- Automotive diagnostic concepts
- Fault/DTC management
- Non-volatile data handling
- Layered firmware architecture

## Disclaimer

This is an educational/reference ECU diagnostic implementation. It is **not automotive production software** and has not been safety-certified or validated for deployment in a road vehicle.

## Author

**Pardhu Attili**

GitHub: [@pardhuattili-web](https://github.com/pardhuattili-web)

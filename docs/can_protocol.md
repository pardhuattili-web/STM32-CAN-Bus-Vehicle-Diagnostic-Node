# CAN Diagnostic Protocol

## CAN IDs

| Direction | CAN ID | Description |
|---|---:|---|
| Tester → ECU | 0x7E0 | Diagnostic request |
| ECU → Tester | 0x7E8 | Diagnostic response |
| ECU → Network | 0x180 | Periodic status telemetry |

## Request Format

`Byte 0 = application payload length`

`Byte 1 = Service ID`

`Byte 2..N = Parameters`

### ECU Status

Request:
```
02 10 01
```

Response:
```
02 50 01
```

### Read Data

Request:
```
03 22 DID_MSB DID_LSB
```

Positive response uses service ID `0x62`.

| DID | Parameter | Scaling |
|---:|---|---|
| 0x0101 | Battery voltage | 0.1 V/bit |
| 0x0102 | Battery current | 0.1 A/bit |
| 0x0103 | Motor temperature | 1 °C/bit |
| 0x0104 | Vehicle speed | 0.1 km/h/bit |
| 0x0105 | State of charge | 1 %/bit |

### DTC Read

Request:
```
02 19 02
```

Response contains the number of stored diagnostic records followed by their identifiers in a full implementation.

### DTC Clear

Request:
```
02 14 FF
```

The demo ECU clears stored DTCs and returns a positive response when successful.

## Negative Response

Malformed or unsupported requests should use:

```
7F <service> <error-code>
```

Suggested codes:

| Code | Meaning |
|---:|---|
| 0x13 | Incorrect message length |
| 0x11 | Service not supported |
| 0x31 | Request out of range |

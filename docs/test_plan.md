# Test Plan

## Functional Tests

| ID | Test | Expected result |
|---|---|---|
| T01 | Valid ECU status request | Positive response |
| T02 | Read battery voltage | Correct DID and scaled value |
| T03 | Read motor temperature | Correct DID and value |
| T04 | Read unknown DID | Negative response |
| T05 | Read stored DTCs | Stored DTC list returned |
| T06 | Clear DTCs | DTC store becomes empty |
| T07 | Invalid request length | Negative response |
| T08 | Unrelated CAN ID | Diagnostic handler not invoked |
| T09 | CAN timeout | Communication fault handled |
| T10 | Restart after persistent storage | DTCs recovered when Flash backend is enabled |

## Evidence to Add Before Final Presentation

- CAN analyzer screenshots
- UART debug output
- STM32CubeIDE build screenshot
- Block diagram
- Hardware photograph
- Test-results table
- Short demo video/GIF

## Validation Status

The repository currently contains design/reference documentation and a firmware scaffold. Hardware execution should be marked **Not Yet Validated** until physical CAN testing has been completed.

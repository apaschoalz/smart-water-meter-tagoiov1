# Hardware

## Componentes
- ESP32 DevKit
- YF-S201 (fluxo)
- Sensor de vazamento (capacitivo)
- Válvula solenoide 12V
- Relé 5V

## Diagrama (ASCII)
[12V] --- [Relé] --- [Válvula] --- [Saída]
↑
GPIO5
[ESP32]
GPIO2 ← [YF-S201] ← [Tubo]
GPIO4 ← [Vazamento]
3.3V/GND
.

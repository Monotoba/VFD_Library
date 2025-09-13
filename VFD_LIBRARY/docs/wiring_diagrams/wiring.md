Perfect. Here’s an updated **wiring diagram with the recommended resistors/divider for 3.3 V MCUs** (ESP32-MAX, STM32 Blue Pill) to safely drive the Noritake 20S401DA1 VFD:

---

## 1️⃣ Wiring Table (with resistors)

| MCU              | MCU Pin         | Resistor Setup                                    | VFD Pin |
| ---------------- | --------------- | ------------------------------------------------- | ------- |
| ACEBOT ESP32-MAX | TX2 (GPIO2)     | 1 kΩ series → RX, optional 510 Ω pull-down to GND | RX      |
| STM32 Blue Pill  | USART2 TX (PA2) | 1 kΩ series → RX, optional 510 Ω pull-down to GND | RX      |
| Arduino Mega     | TX1/TX2         | Direct connection (5 V logic)                     | RX      |
| All              | GND             | —                                                 | GND     |
| All              | 5 V             | —                                                 | VCC     |

---

## 2️⃣ ASCII Diagram

```
ACEBOT ESP32-MAX (3.3V MCU)
   TX2 (GPIO2) ---[1kΩ]---+----> VFD RX
                           |
                          [510Ω]
                           |
                          GND
   GND ---------------------------> GND
   5V  ---------------------------> VCC

STM32 Blue Pill (3.3V MCU)
   USART2 TX (PA2) ---[1kΩ]---+----> VFD RX
                               |
                              [510Ω]
                               |
                              GND
   GND ---------------------------> GND
   5V  ---------------------------> VCC

Arduino Mega (5V MCU)
   TX1/TX2 ----------------------> VFD RX
   GND ---------------------------> GND
   5V  ---------------------------> VCC
```

---

### Notes

1. **Series 1 kΩ** protects the MCU from spikes or short circuits.
2. **Optional 510 Ω pull-down** further limits current in case the VFD RX tries to drive the line.
3. For **5 V MCUs** (Arduino Mega, Uno with second serial), no voltage divider is needed.
4. Ensure the **VFD has a stable 5 V supply**, since logic lines are dependent on proper VCC.

---



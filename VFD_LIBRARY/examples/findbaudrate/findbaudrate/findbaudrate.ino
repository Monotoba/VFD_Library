// ============================================================================
// Filename: baudfinder.ino
// Version: 1.0.0
// Date: 2025-09-12
// Author: Randall MOrgan
// Maintainer: rmorgan62@gmail.com
// Description:
//   Example program for the VFD library demonstrating how to identify the
//   correct serial baudrate for the Noritake 20S401DA1 Vacuum Fluorescent
//   Display (4x20).
//
//   The program cycles through a list of common baudrates supported by ESP32,
//   STM32, and AVR microcontrollers. For each baudrate, it:
//     - Initializes the VFD with the selected baudrate
//     - Clears the display
//     - Prints "Testing" and the baudrate number
//     - Pauses for 2 seconds before trying the next baudrate
//
//   This helps users determine which baudrate their VFD module is configured
//   to use. Once the correct baudrate is identified, that value can be used
//   in normal operation with the VFD library.
// ============================================================================


#include <VFDLib.h>

// Pick which serial port for VFD (ESP32 has Serial1, Serial2)
VFDLib vfd(Serial1);

// Common baudrates to test
const long baudRates[] = {
  300, 600, 1200, 2400, 4800,
  9600, 14400, 19200, 28800, 38400,
  57600, 115200, 230400, 460800, 921600, 2000000
};

const size_t baudCount = sizeof(baudRates) / sizeof(baudRates[0]);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println(F("=== VFD Baudrate Finder ==="));

  // Use the built-in finder
  vfd.findBaudrates(baudRates, baudCount, 2000);
}

void loop() {
  // Nothing — the finder cycles forever
}

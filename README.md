# VFD\_Library

## Overview

The `VFD_Library` is an Arduino C++ library for controlling the **Noritake 20S401DA1 4x20 Vacuum Fluorescent Display (VFD)**. It provides functions for basic display control, custom glyphs, and rendering large ASCII characters (BIGASCII) with horizontal and vertical scrolling.

This library is designed to work with **ACEBOTT ESP32-MAX** or any Arduino-compatible board with a serial interface to the VFD.

---

## Features

* Clear display and set cursor position
* Adjust display brightness
* Send ASCII text to display
* Define and display **up to 8 custom glyphs**
* BIGASCII letters for **A-Z, 0-9**
* Write large ASCII messages (`writeBigMsg`) with optional centering and vertical scroll
* Horizontal scrolling of BIGASCII text (`hScrollBigMsg`)
* Vertical scrolling of BIGASCII text (`vScrollBigMsg`)
* Example demo provided

---

## Hardware Connection

* **VFD TX / RX** → Arduino/ESP32 Serial port (e.g., `Serial1`)
* **VFD Power**: Check datasheet for 20S401DA1 voltage and current requirements (typically 20-25V filament and 5V logic)
* Ensure proper level conversion if your MCU is 3.3V and VFD logic is 5V.

---

## Library Files

```
VFD_Library/
├─ VFD.h
├─ VFD.cpp
├─ library.properties
├─ keywords.txt
├─ .gitignore
└─ examples/
   └─ demo.ino
```

### `VFD.h`

* Contains class declaration for `VFD`
* Declares methods for display control, glyphs, and BIGASCII functions

### `VFD.cpp`

* Implements all functions declared in `VFD.h`
* Includes BIGASCII character arrays
* Implements scrolling routines

### `examples/demo.ino`

* Demonstrates all features of the library:

  * Custom glyphs
  * BIGASCII single-word display
  * Horizontal and vertical scrolling of BIGASCII text

### `library.properties`

* Provides metadata for Arduino IDE 2.x

### `keywords.txt`

* Provides syntax highlighting in Arduino IDE

### `.gitignore`

* Ignores temporary build files and `.idea`/`.vscode` folders

---

## Example Usage

```cpp
#include <VFD.h>

VFD vfd(Serial);

void setup() {
    vfd.begin(9600);
    vfd.clear();
    vfd.setBrightness(4);

    // Show custom glyphs
    uint8_t smiley[8] = {0b00000,0b01010,0b01010,0b00000,0b10001,0b01110,0b00000,0b00000};
    vfd.defineGlyph(0, smiley);
    vfd.setCursor(1,1);
    vfd.writeGlyph(0);

    // BIGASCII text
    vfd.writeBigMsg("BIG SKY", true, false);

    // Horizontal scroll
    vfd.hScrollBigMsg("WELCOME TO THE VFD DEMO", 200);
}

void loop() {
    // Optional continuous demo
}
```

[![Arduino CI](https://github.com/Monotoba/VFD_Library/actions/workflows/ci.yml/badge.svg)](https://github.com/Monotoba/VFD_Library/actions/workflows/ci.yml)

---

## License

This library is released under the **MIT License**. See LICENSE file.

---

## References

* [Noritake VFD 20S401DA1 Datasheet](https://www.noritake-itron.com/products/vfd)
* Arduino [Serial Reference](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
* ACEBOTT ESP32-MAX Documentation

---

# Note
This README is duplicated at the repository root.  
If you update one, please update the other.

---

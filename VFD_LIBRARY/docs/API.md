Perfect 👍 Here’s the full **Markdown-formatted `API.md`** file, with your requested author/maintainer details filled in. You can copy-paste directly into your repo.

---

````markdown
# VFD Library API Reference

**Library Name:** `VFD`  
**Target Display:** Noritake 20S401DA1 VFD (4x20)  
**Version:** 1.0.0  
**Date:** 2025-09-12  
**Author:** Randall Morgan  
**Maintainer:** Randall Morgan  
**Repository:** [git@github.com:Monotoba/VFD_Library.git](git@github.com:Monotoba/VFD_Library.git)  
**License:** MIT  

---

## Class: `VFD`

### Constructor
```cpp
VFD vfd(HardwareSerial& serialPort);
````

* **Description:** Creates a VFD object bound to the given serial port.
* **Parameters:**

  * `serialPort` – Reference to a `HardwareSerial` instance (e.g., `Serial`, `Serial1`, `Serial2`).
* **Example:**

```cpp
VFD vfd(Serial2);
```

---

### `begin`

```cpp
void begin(long baudrate);
```

* **Description:** Initializes the display at the specified baudrate.
* **Parameters:**

  * `baudrate` – Typical values: 9600, 19200, 38400, etc.
* **Example:**

```cpp
vfd.begin(9600);
```

---

### `clear`

```cpp
void clear();
```

* **Description:** Clears the display and resets cursor to home (1,1).

---

### `setCursor`

```cpp
void setCursor(uint8_t row, uint8_t col);
```

* **Description:** Moves cursor to the specified position.
* **Parameters:**

  * `row` – 1–4
  * `col` – 1–20
* **Example:**

```cpp
vfd.setCursor(2, 5);
```

---

### `write`

```cpp
void write(const char* text);
```

* **Description:** Writes ASCII text at the current cursor.

---

### `defineGlyph`

```cpp
void defineGlyph(uint8_t index, const uint8_t bitmap[8]);
```

* **Description:** Defines a custom 5×8 character bitmap.
* **Parameters:**

  * `index` – Slot 0–7 (character codes `0x00–0x07`)
  * `bitmap[8]` – Each byte defines one row of pixels (5 LSB used).
* **Example:**

```cpp
uint8_t smiley[8] = {
  0b00000,
  0b01010,
  0b01010,
  0b00000,
  0b10001,
  0b01110,
  0b00000,
  0b00000
};
vfd.defineGlyph(0, smiley);
```

---

### `writeGlyph`

```cpp
void writeGlyph(uint8_t index);
```

* **Description:** Prints a previously defined glyph at the cursor.

---

### `setBrightness`

```cpp
void setBrightness(uint8_t level);
```

* **Description:** Sets brightness level.
* **Parameters:**

  * `level` – 1 (lowest) … 4 (highest).

---

### `writeBigMsg`

```cpp
void writeBigMsg(const char* msg, bool center = false, bool vscroll = false);
```

* **Description:** Writes a message using 4-row-tall BIGASCII characters.
* **Parameters:**

  * `msg` – ASCII string (`A–Z`, `0–9`, space).
  * `center` – If true, horizontally centers text.
  * `vscroll` – If true, vertically scrolls text onto screen.

---

### `hScrollBigMsg`

```cpp
void hScrollBigMsg(const char* msg, int delayMs = 150);
```

* **Description:** Scrolls BIGASCII text horizontally across all 4 lines.
* **Parameters:**

  * `msg` – Text string.
  * `delayMs` – Delay between shifts (ms).

---

### `vScrollBigMsg`

```cpp
void vScrollBigMsg(const char* msg, int delayMs = 500);
```

* **Description:** Scrolls BIGASCII text vertically up the display.
* **Parameters:**

  * `msg` – Text string.
  * `delayMs` – Delay between shifts (ms).

---

### `findBaudRate`

```cpp
long findBaudRate();
```

* **Description:** Cycles through common baud rates (300–2,000,000), sends a test string, and waits for a valid response from the display.
* **Returns:** Detected baudrate, or `-1` if none found.

---

## Custom Glyph Slots

The display supports **8 custom characters** (`0x00–0x07`).
Use `defineGlyph()` to create bitmaps, then `writeGlyph()` to display them.

---

## BIGASCII Characters

* Supported: `A–Z`, `0–9`, and space (` `).
* Each character is defined as a 4×N block pattern in the library.
* Unsupported characters print as blanks.

---

## Example Usage

```cpp
#include <VFD.h>

VFD vfd(Serial);

void setup() {
  vfd.begin(9600);
  vfd.clear();
  vfd.setCursor(1,1);
  vfd.write("Hello VFD!");

  // Custom glyph
  uint8_t heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
  };
  vfd.defineGlyph(0, heart);
  vfd.setCursor(2,1);
  vfd.writeGlyph(0);

  // BIGASCII demo
  vfd.clear();
  vfd.writeBigMsg("VFD DEMO", true, false);
}

void loop() {
  vfd.hScrollBigMsg("SCROLLING BIG TEXT DEMO!", 150);
}
```

---

## Support / Contact

* **Maintainer:** Randall Morgan
* **Repository:** [git@github.com\:Monotoba/VFD\_Library.git](git@github.com:Monotoba/VFD_Library.git)
* Issues and pull requests are welcome.

---

```

---

Do you also want me to prepare a **`PROTOCOL.md`** file documenting the escape codes and commands supported by the Noritake VFD (cursor positioning, clear, brightness, etc.), or should we keep that separate?
```


#include <VFD.h>

VFD vfd(Serial);

void setup() {
  // Initialize VFD
  vfd.begin(9600);
  vfd.clear();
  vfd.setBrightness(4);

  // --- Custom glyphs ---
  uint8_t smiley[8] = {0b00000,0b01010,0b01010,0b00000,0b10001,0b01110,0b00000,0b00000};
  uint8_t heart[8]  = {0b00000,0b01010,0b11111,0b11111,0b11111,0b01110,0b00100,0b00000};
  uint8_t poop[8]   = {0b00000,0b01110,0b11111,0b11111,0b11111,0b01110,0b00100,0b00000};
  uint8_t star[8]   = {0b00100,0b11111,0b01110,0b11111,0b00100,0b00100,0b00000,0b00000};

  vfd.defineGlyph(0, smiley);
  vfd.defineGlyph(1, heart);
  vfd.defineGlyph(2, poop);
  vfd.defineGlyph(3, star);

  delay(500);
}

void loop() {
  // --- Custom glyph demo ---
  vfd.clear();
  vfd.setCursor(1, 1);
  vfd.write("Glyph Demo:");
  vfd.setCursor(2, 1); vfd.writeGlyph(0);
  vfd.setCursor(2, 3); vfd.writeGlyph(1);
  vfd.setCursor(2, 5); vfd.writeGlyph(2);
  vfd.setCursor(2, 7); vfd.writeGlyph(3);
  delay(3000);

  // --- BIGASCII single-word demo ---
  vfd.clear();
  vfd.writeBigMsg("VFD DEMO", true, false);
  delay(3000);

  // --- Horizontal scroll demo ---
  vfd.clear();
  vfd.hScrollBigMsg("WELCOME TO BIG ASCII SCROLL DEMO 123!", 150);
  delay(1000);

  // --- Vertical scroll demo ---
  vfd.clear();
  vfd.vScrollBigMsg("VFD DEMO 123 HELLO WORLD!", 500);
  delay(1000);

  // --- Basic commands demo ---
  vfd.clear();
  vfd.setBrightness(1);
  vfd.setCursor(1,1);
  vfd.write("Brightness 1");
  delay(1000);
  vfd.setBrightness(2);
  vfd.clear();
  vfd.setCursor(1,1);
  vfd.write("Brightness 2");
  delay(1000);
  vfd.setBrightness(3);
  vfd.clear();
  vfd.setCursor(1,1);
  vfd.write("Brightness 3");
  delay(1000);
  vfd.setBrightness(4);
  vfd.clear();
  vfd.setCursor(1,1);
  vfd.write("Brightness 4");
  delay(1000);

  // Repeat demo loop
}

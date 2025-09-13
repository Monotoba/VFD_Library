// ============================================================================
// Filename: demo.ino
// Version: 1.0.0
// Date: 2025-09-12
// Author: Randall Morgan
// Maintainer: https://github.com/Monotoba/VFD_Library
// Description:
//   Comprehensive demo program for the VFD library controlling the
//   Noritake 20S401DA1 Vacuum Fluorescent Display (4x20).
//
//   Demonstrates the following features of the VFD library:
//     - Initialization, clearing the screen, and brightness control
//     - Defining and displaying custom glyphs (smiley, heart, poop, star)
//     - Rendering BIGASCII text (letters A–Z and digits 0–9)
//     - Centering BIGASCII messages on the display
//     - Horizontal scrolling of BIGASCII text across the screen
//     - Vertical scrolling of BIGASCII text across multiple lines
//     - Stepwise demonstration of brightness levels (1–4)
//
//   This file is meant to serve as both a functional demo and a usage guide
//   for developers integrating the VFD library into their Arduino projects.
// ============================================================================



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

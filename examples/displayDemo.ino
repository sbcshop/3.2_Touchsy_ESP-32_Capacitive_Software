#include <TFT_eSPI.h> // include display control library
#include <SPI.h>
#include "Free_Fonts.h"  // include this header for custom fonts

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define TFT_BACK_LIGHT 5  // GPIO to which backlight of TFT connected

void setup(void) {
  pinMode( TFT_BACK_LIGHT, OUTPUT );    // set backlight pin as OUTPUT
  digitalWrite( TFT_BACK_LIGHT, HIGH ); // activate backlight
  
  tft.init();  // initialize display
  tft.setRotation(3); // set suitable rotation for display
  tft.fillScreen(TFT_BLACK); // background color setting

  tft.setTextSize(2); // increase size of text
  tft.setTextColor(TFT_WHITE, TFT_BLACK);        // Set colour
  tft.setFreeFont(FF18); // set Font type
  tft.drawString("Hello...", 80, 100, GFXFF);
  delay(250);

  tft.setTextSize(1); // to normal Size of Text
  tft.fillScreen(TFT_BLACK); // background color
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // set text color
  tft.setFreeFont(FF18); // set Font type
  tft.drawString("3.2\" Touchsy ESP32", 50, 25, GFXFF);

  tft.setFreeFont(FF1);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);        
  tft.drawString("* Capacitive *", 80, 60, GFXFF);
  
  tft.setTextColor(TFT_WHITE, TFT_BLACK);        
  tft.setFreeFont(FSBI12);
  tft.drawString("Thank you for Buying!", 50, 120, GFXFF);
  
  tft.setTextColor(TFT_BLUE, TFT_BLACK);       
  tft.setFreeFont(FSSBO12);
  tft.drawString("SB Components", 70, 180, GFXFF);

  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // set text color
  tft.setFreeFont(FF1);
  tft.drawString("shop.sb-components.co.uk", 30, 220, GFXFF);
  delay(1000);
}

void loop() {
  delay(10);
}


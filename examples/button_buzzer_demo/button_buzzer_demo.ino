#include <TFT_eSPI.h> // include display control library
#include <SPI.h>
#include "Free_Fonts.h"  // include this header for custom fonts

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library

#define TFT_BACK_LIGHT 5  // GPIO to which backlight of TFT connected

const int buzzerPin = 40; // buzzer at GPIO40
const int userButton1 = 4; // button 1 at GPIO4
const int userButton2 = 6; // button 1 at GPIO6

void beep(int note, int duration){  // need note frequency and time duration (in millis)
  tone(buzzerPin, note, duration);
  delay(duration);
}

void setup(void) {
  pinMode(userButton1, INPUT_PULLUP); // set button1 pin to INPUT with PULLUP
  pinMode(userButton2, INPUT_PULLUP);
  
  pinMode(buzzerPin, OUTPUT); // set Buzzer pin as OUTPUT
  pinMode( TFT_BACK_LIGHT, OUTPUT );    // set backlight pin as OUTPUT
  digitalWrite( TFT_BACK_LIGHT, HIGH ); // activate backlight
  
  tft.init();  // initialize display
  tft.setRotation(3); // set suitable rotation for display
  tft.setTextSize(1); // to normal Size of Text
  tft.fillScreen(TFT_BLACK); // background color
  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // set text color
  tft.setFreeFont(FF18); // set Font type
  tft.drawString("3.2\" Touchsy ESP32", 50, 25, GFXFF);

  tft.setFreeFont(FF1);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);        
  tft.drawString("* Capacitive *", 80, 60, GFXFF);


  tft.setTextColor(TFT_CYAN, TFT_BLACK); // set text color
  tft.setFreeFont(FF1);
  tft.drawString("Press Buttons to Test!", 40, 200, GFXFF);
  delay(1000);
}

void loop() {
  if (digitalRead(userButton1)==0){
    Serial.println("Button 1 Pressed!");
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);  
    tft.setFreeFont(FSB9);
    tft.drawString("BT1", 140, 160, GFXFF); 
    beep(1245,500);
    delay(50);
  }

  if (digitalRead(userButton2)==0){
    Serial.println("Button 2 Pressed!");
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);  
    tft.setFreeFont(FSB9);
    tft.drawString("BT2", 140, 160, GFXFF);
    beep(1245,500);
    delay(50);
  }
  tft.drawString("          ", 140, 160, GFXFF);
  delay(10);
}


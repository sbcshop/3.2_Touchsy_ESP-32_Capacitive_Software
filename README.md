# 3.2_Touchsy_ESP-32_Capacitive_Software
<img src="https://github.com/sbcshop/3.2_Touchsy_HAT_Resistive_Software/blob/main/images/Touchsy%20banner.jpg">

Touchsy ESP-32 offers the ideal display solution for users who favor ESP-32 over Raspberry Pi Pico W. With ESP-32, you enjoy the flexibility to program your display using the Arduino platform, making it compatible with a wide range of projects and applications, including IoT and robotics. 

This Github provides getting started guide for **ESP32 Capacitive** Variant of Touchsy Family.

You also have the choice between [**Resistive**](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/tree/main) and **Capacitive** touchscreens to suit your specific requirements. Additionally, the additional GPIO pins breakout provided for convenience of connecting additional hardware to your display.

Here are the features and specifications that make Touchsy ESP-32 a unique and must-have accessory:

### Features:
- Integrated ESP32-S3 WROOM 1 module, supports 2.4 GHz Wi-Fi and Bluetooth 5 (LE)
- 3.2” TFT Capacitive Touch Display for visual interaction
- SD card slot for storage and data transfer
- Battery port connector with Battery Management for portable use (3.7V Lithium)
- Remaining GPIO pins breakout for connecting more hardware, Serial and direct USB 
- Type C interface for both Programming and Power
- Additional power supply facility for use with other peripheral
- Perfect security mechanism, support AES-128/256, Hash, RSA, HMAC, digital signatures and secure boot
- RESET button. Press this button to reset the system.
- BOOT button. Hold down the Boot button and press the RESET button to initiate firmware download mode. Users can download firmware through the serial port
- 2 additional programmable buttons for customizable control options


### Specifications:
- Wi-Fi Protocol: 802.11b/g/n (802.11n up to 150Mbps) Wi-Fi Frequency Range: 2.402GHz - 2.483Ghz
- Support Bluetooth 5
- Operating voltage of pins 3.3V and board supply 5V
- 3.2” Display with resolution 240 × 320
- ILI934 Display Driver
- FT6236 capacitive touch controller
- Appearance: RGB
- Colors: 65K/262K
- Viewing Angle(in degree): Left:70, Right:70, Up:50, Down:70 
- Operating Temperature is -20℃~70℃
- Storage Temperature is -30℃~80℃

## Getting Started with 3.2 Touchsy ESP-32 Capacitive
### Pinout
<img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/images/Touchsy%20ESP32%20cap%20pinout.jpg">

- (1) 3.2” Capacitive Touch Display 
- (2) Extra GPIO breakout
- (3) Buzzer 
- (4) Battery connection port
- (5) Power pins breakout 
- (6) Type C for Programming and Power both
- (7) Additional GPIO breakout 
- (8) SD card slot 
- (9) ESP32 S3 module
- (10) Boot Button
- (11) Reset Button
- (12) Two Programmable Buttons


### Interfacing Details
- Display and Capacitive Touch controller interfacing with ESP32

    For Display SPI interfacing done with ESP32
    | ESP32 | Display | Code variables | Function |
    |---|---|---|---|
    | IO12 | DC/SCL SPI  | TFT_SCLK   |Clock pin of SPI interface for Display|
    | IO11 | SDI SPI/SDA | TFT_MOSI   | MOSI (Master OUT Slave IN) pin of SPI interface|
    | IO10 | CS/SPI CS   | TFT_CS  | Chip Select pin of SPI interface|
    | IO21 | WR/SPI D/C  | TFT_DC  | Data/Command pin of SPI interface|
    | EN   | RESET       | TFT_RST | Display Reset pin, Directly connected to enable pin|
    | IO5  |Driven via Transistor  | TFT_BACKLIGHT_PIN |Backlight of display|

  Display setting code snippets view:
  ```
    //Define display SPI interfacing pins inside C:\Users\..\Documents\Arduino\libraries\TFT_eSPI\User_Setup.h
    #define TFT_MOSI 11
    #define TFT_SCLK 12
    #define TFT_CS   10  // Chip select control pin
    #define TFT_DC   13  // Data Command control pin
    #define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST
  ```
    For capacitive Touch I2C interfacing done
    | ESP32 | Capacitive Touch | Code variables | Function |
    |---|---|---|---|
    | IO38 | SDA | I2C_SDA  |serial data pin of I2C interfacing|
    | IO39 | SCL | I2C_SCL  |serial clock pin of I2C interfacing|
  ```
    //define I2C interface of Touch controller with ESP32, inside main code file
    #define I2C_SDA 38
    #define I2C_SCL 39
  ```
- ESP32 and micro SD card interfacing
    | ESP32| microSD Card | Function |
    |---|---|---|
    |IO42 | SCLK |Clock pin of SPI interface for microSD card |
    |IO2 | DIN  | MOSI (Master OUT Slave IN) data pin of SPI interface|
    |IO41 | DOUT | MISO (Master IN Slave OUT) data pin of SPI interface|
    |IO1 | CS   | Chip Select pin of SPI interface|

  Sdcard setting code snippets view:
  ```
   //Define SPI interfacing pins for micro SD card with ESP32
    #define SD_MOSI 2
    #define SD_MISO 41
    #define SD_SCK 42
    #define SD_CS 1
  ```
  
- Buttons, Buzzer and LED Interfacing with ESP32
    | ESP32 | Buttons | Function |
    |---|---|---|
    |IO4 | BT1 |Programmable button|
    |IO6 | BT2 |Programmable button|
    |IO0 | Boot | Boot Button|
  
    | ESP32 | Hardware |
    |---|---|
    |IO40 | Buzzer |
    |IO15 | LED |

  Code snippets:
  ``` 
    const int buzzerPin = 40; // create variable for buzzer at GPIO40
    const int userButton1 = 4; //for programmable button 1 at GPIO4
    const int userButton2 = 6; //for programmable button 1 at GPIO6
    const int LED = 3;
  ```
- Breakout GPIOs
  
    Breakout 1
    | ESP32 |Physical Pin | Multi-Function |
    |---|---|---|
    |D- | 13 | RTC_GPIO19, GPIO19, U1RTS, ADC2_CH8, CLK_OUT2, USB_D- |
    |D+ | 14 | RTC_GPIO20, GPIO20, U1CTS, ADC2_CH9, CLK_OUT1, USB_D+ |
    |GP9 | 4 | RTC_GPIO9, GPIO9, TOUCH9, ADC1_CH8, FSPIHD |
    |GP3 | 15 | RTC_GPIO3, GPIO3, TOUCH3, ADC1_CH2 |
    |GP46 | 16 | GPIO46 |
    |GP21 | 18 | RTC_GPIO21, GPIO21 |

    Breakout 2
    | ESP32 |Physical Pin | Multi-Function |
    |---|---|---|
    |3V3  | - | Positive Supply 3.3V |
    |GP43 | 37 | U0TXD, GPIO43, CLK_OUT1 |
    |GP44 | 36 | U0RXD, GPIO44, CLK_OUT2 |
    |GP8  | 12 | RTC_GPIO8, GPIO8, TOUCH8, ADC1_CH7  |
    |GP16 | 9 | RTC_GPIO16, GPIO16, U0CTS, ADC2_CH5, XTAL_32K_N |
    |GND  | - | Ground pin |

### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 board support into IDE, for this first you need to add below link into preference:
     ``` https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
     
### 2. Installing Libraries
   - Download [library zip file](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/libraries.zip) provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### 3. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/tree/main/examples) in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on ESP32 of Touchsy.
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/upload_process.gif">
   - If you plan to use display related code with any custom header files then follow below image steps to create header file inside main code, for demonstration we have shown how to use custom fonts. To make your task easy, we have added font header into code folder, so this step not need when you download complete github.
     
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/images/headerFile_add.gif">
     
   - Checkout other examples below and build your own custom program codes using those references.

### Example Codes
   - [Example 1](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/tree/main/examples/displayDemo) : Display demo code
   - [Example 2](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/tree/main/examples/touchDemo) : Touch demo code
   - [Example 3](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/tree/main/examples/button_buzzer_demo) : Button & Buzzer testing with display code
   - [Example 4](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/tree/main/examples/sdcard_Demo) : Demo with micro SDcard
   - and [Many more...](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/tree/main/examples)

   Now you are ready to try out your own codes, **_Happy Coding!_**
   
## Resources
  * [Schematic](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Hardware/blob/main/Design%20Data/Sch%203.2%20Inch%20Touchsy%20based%20on%20ESp32(capacitive).pdf)
  * [Hardware Files](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Hardware)
  * [Step File](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Hardware/blob/main/Mechanical%20Data/Step%203.2%20Inch%20Touchsy%20based%20on%20ESp32(capacitive).step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/documents/esp32-s3_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)


## Related Products
   * [3.2" Touchsy ESP32](https://shop.sb-components.co.uk/products/touchsy-3-2-touch-lcd-display-based-on-esp32-mcu?variant=40828141174867) - 3.2" Touchsy ESP32 with Resistive and Capacitive version. 
   * [3.2" Touchsy Pico W](https://shop.sb-components.co.uk/products/touchsy-3-2-touch-lcd-display-based-on-pico-w?variant=40828148744275) - 3.2" Touchsy Pico W with Resistive and Capacitive version.
   * [3.2" Touchsy Breakout](https://shop.sb-components.co.uk/products/touchsy-3-2-touch-lcd-display-breakout-board?variant=40828158476371) - 3.2" Touchsy Breakout with Resistive and Capacitive version.
   * [3.2" Touchsy HAT](https://shop.sb-components.co.uk/products/touchsy-3-2-touch-lcd-display-for-raspberry-pi?_pos=3&_sid=6c0f5891d&_ss=r) - 3.2" Touchsy HAT with Resistive version for Raspberry Pi.
   * [1.28" Round Touch LCD HAT](https://shop.sb-components.co.uk/products/1-28-round-touch-lcd-hat-for-raspberry-pi?_pos=1&_sid=b6ecd2f9c&_ss=r) - 1.28" Round Touch LCD HAT for Raspberry Pi.

## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>



## Related Products
   * [3.2" Touchsy ESP32](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-based-on-esp32-mcu) - 3.2" Touchsy ESP32 with Resistive and Capacitive version. 
   * [3.2" Touchsy Pico W](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-based-on-pico-w) - 3.2" Touchsy Pico W with Resistive and Capacitive version.
   * [3.2" Touchsy Breakout](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-breakout-board) - 3.2" Touchsy Breakout with Resistive and Capacitive version.
   * [3.2" Touchsy HAT](https://shop.sb-components.co.uk/collections/pre-order/products/touchsy-3-2-touch-lcd-display-for-raspberry-pi) - 3.2" Touchsy HAT with Resistive version for Raspberry Pi.
   * [1.28" Round Touch LCD HAT](https://shop.sb-components.co.uk/products/1-28-round-touch-lcd-hat-for-raspberry-pi?_pos=2&_sid=6c0f5891d&_ss=r) - 1.28" Round Touch LCD HAT for Raspberry Pi.

## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>

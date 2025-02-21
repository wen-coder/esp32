#ifndef FONT_FONTLIBRARY_H_
#define FONT_FONTLIBRARY_H_
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
// #define OLED_MOSI   13
// #define OLED_CLK   12
// #define OLED_DC    27
// #define OLED_CS    26
// #define OLED_RESET 14

#define OLED_MOSI   13
#define OLED_CLK   25
#define OLED_DC    27
#define OLED_CS    26
#define OLED_RESET 14


#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

void task_show_font_(void *pvParameters);

enum show_position {
    mid,
    left,
    right,
};



#endif

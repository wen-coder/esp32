#ifndef KEY_
#define KEY_
#include <Wire.h>
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

// #define KEY_OUT1 26
// #define KEY_OUT2 25
// #define KEY_IN1  9
// #define KEY_IN2  10
// #define KEY_IN3  11
// #define KEY_IN4  12

#define KEY_OUT1 27
#define KEY_OUT2 27
#define KEY_IN1  28
#define KEY_IN2  28
#define KEY_IN3  28
#define KEY_IN4  28

enum key_state {
    key_up,
    key_down,
    key_left,
    key_right,
    key_enter,
    key_back,
    key_none
};

void key_scan(void *pvParameters);

#endif

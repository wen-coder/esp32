#ifndef KEY_KEY_
#define KEY_KEY_
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

#define KEY_OUT1 5
#define KEY_OUT2 18
#define KEY_IN1  19
#define KEY_IN2  21
#define KEY_IN3  22
#define KEY_IN4  23

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

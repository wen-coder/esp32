#ifndef BLUE_TOOTH_H
#define BLUE_TOOTH_H



#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "BluetoothSerial.h"



void task_blue_tooth(void *pvParameters);
void Bluetooth_Event(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);  //蓝牙事件回调函数


#endif

#include <Font_library.h>
#include <blue_tooth.h>
#include <key.h>
#include <esp_system.h>


TaskHandle_t task_show_font_Handle;  //显示屏幕的任务句柄
TaskHandle_t blue_tooth_Handle;      // 蓝牙的任务句柄
TaskHandle_t key_scan_Handle;        //按键扫描的任务句柄  

void setup() {
  Serial.begin(9600);
  
  xTaskCreate(task_show_font_, "task_show_font_", 10000, NULL, 3, &task_show_font_Handle);
  xTaskCreate(key_scan, "key_scan", 10000, NULL, 3, &key_scan_Handle);
  xTaskCreate(task_blue_tooth, "task_blue_tooth", 10000, NULL, 3, &blue_tooth_Handle);
}

void loop() {
  delay(2000);
}
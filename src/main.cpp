#include <Font_library.h>
#include <blue_tooth.h>
TaskHandle_t task_show_font_Handle;  //显示屏幕的任务句柄

TaskHandle_t blue_tooth_Handle; // 蓝牙的任务句柄
void setup() {
  Serial.begin(9600);
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  

  xTaskCreate(task_show_font_, "task_show_font_", 10000, NULL, 1, &task_show_font_Handle);
  xTaskCreate(task_blue_tooth, "task_blue_tooth", 10000, NULL, 2, &blue_tooth_Handle);
}

void loop() {
}

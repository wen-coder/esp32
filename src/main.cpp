#include <fontlibrary.h>
#include <bluetooth.h>
#include <key.h>
#include <esp_system.h>
#include <global.h>

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
  if (Serial.available() > 0) {
    // 读取串口输入的一行数据
    String input = Serial.readStringUntil('\n');
    // 打印接收到的数据
    int number = input.toInt();

    // 检查转换是否成功
    if (number != 0 || input == "0") {
      // 打印接收到的数字
      Serial.print("你输入的数字是：");
      Serial.println(number);
       xQueueSend(input_Queue, &number, portMAX_DELAY);
    } else {
      // 输入不是有效的数字
      Serial.println("输入无效，请输入一个有效的数字。");
    }
    // 提示用户可以继续输入
    Serial.println("请输入一个新的数字，按回车键结束：");
  }
  delay(200);
}
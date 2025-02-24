#ifndef GLOBALS_H
#define GLOBALS_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

// 声明全局队列
extern QueueHandle_t input_Queue;

#endif // GLOBALS_H
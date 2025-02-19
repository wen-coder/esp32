#include <key.h>
QueueHandle_t keyQueue;
void key_init()
{
    pinMode(KEY_IN1, INPUT);
    pinMode(KEY_IN2, INPUT);
    pinMode(KEY_IN3, INPUT);
    pinMode(KEY_IN4, INPUT);
    pinMode(KEY_OUT1, OUTPUT);
    pinMode(KEY_OUT2, OUTPUT);

    
}
char KEY_OUT[2] = {KEY_OUT1, KEY_OUT2};
char KEY_IN[4] = {KEY_IN1, KEY_IN2, KEY_IN3, KEY_IN4};
void key_scan(void *pvParameters) {
    key_init();
    
    while (1)
    {
        for(int i = 0; i < 2; i++)
        {
            digitalWrite(KEY_OUT[i], HIGH);
            for(int j = 0; j < 3; j++)
            {
                if(digitalRead(KEY_IN[i]) == 1)
                    {
                        vTaskDelay(20); //  消抖
                        if(digitalRead(KEY_IN[i]) == 1){
                            int keyPress = i * 2 + j ;  // 计算按键编号
                            log_i("key_scan, keyPress = %d\n", keyPress);
                            //xQueueSend(keyQueue, &keyPress, portMAX_DELAY);
                            break;
                        }
                        
                    }
            }
            digitalWrite(KEY_OUT[i], LOW);  // 关闭输出引脚以避免干扰
        }
        vTaskDelay(100); // 等待20ms
    }
    
}


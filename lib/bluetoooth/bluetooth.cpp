#include <bluetooth.h>
#include <Wire.h>
BluetoothSerial SerialBT;
void task_blue_tooth(void *pvParameters)
{int i;
char BT[9]={0};
int LED = 4; //灯
    
    String device_name = "ESP32-BT";
    SerialBT.begin(device_name);  //Bluetooth device name
 
    Serial.println("The device started, now you can pair it with bluetooth!");
    while (1)
    {
        log_i("BT_task");
        if (Serial.available()) 
        {
            SerialBT.write(Serial.read());
        }
         if (SerialBT.available()) 
        {
//    Serial.write(SerialBT.read());
            delay(50);
            for (i = 0; i < 9; i++)
            {
                BT[i] = SerialBT.read();
        //       Serial.print(BT[i]);//打印出数组里的内容
            }
            if(BT[0]=='w'&&BT[1]=='u')
            {
                digitalWrite(LED, HIGH);//亮
                Serial.println("点灯成功");
            }else
            {
                digitalWrite(LED, LOW);//不亮
                Serial.println("抱歉，您发送的指令不对哦");
            }      
        }
        vTaskDelay(1000);
    }
}

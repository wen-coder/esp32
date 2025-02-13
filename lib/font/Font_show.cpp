#include <Font_library.h>

#include <U8g2lib.h>
void testdrawbitmap(void);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);



void task_show_font_(void *pvParameters) {
  U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 25, /* data=*/ 13, /* cs=*/ 26, /* dc=*/ 27, /* reset=*/ 14);
  
  u8g2.begin();
  u8g2.enableUTF8Print();	

  for(;;)
  {
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
  u8g2.setFontDirection(2);
  u8g2.clearBuffer();
  u8g2.setCursor(100, 15);
  u8g2.print("Hello World!");
  u8g2.setCursor(100, 40);
  u8g2.print("你好你好你好你好11112");		// Chinese "Hello World" 
  u8g2.sendBuffer();
   
  vTaskDelay(2000);
  }
  
 

  // if(!display.begin(SSD1306_SWITCHCAPVCC)) {
  //   Serial.println(F("SSD1306 allocation failed "));
  //   for(;;); // Don't proceed, loop forever
  // }

  

  // display.flipScreenVertically();
  // // Show initial display buffer contents on the screen --
  // // the library initializes this with an Adafruit splash screen.
  // display.display();

  // delay(2000); // Pause for 2 seconds

  // // Clear the buffer
  // display.clearDisplay();
  // while (1)
  // {
  //   testdrawbitmap();    // Draw a small bitmap image/* code */
  // };
}

void testdrawbitmap(void) {
  //display.clearDisplay();
  //display.drawBitmap(0, 0 ,qing_yuan_ji_bao1, LOGO_WIDTH * 4 , LOGO_HEIGHT, 1);
 // display.display();
  vTaskDelay(2000);
}
#include <Font_library.h>

#include <U8g2lib.h>
void testdrawbitmap(void);
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//   OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
void show_to_screen(U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2, const char *str, const uint8_t  *font, int x, int y); 


void task_show_font_(void *pvParameters) {
  U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 25, /* data=*/ 13, /* cs=*/ 26, /* dc=*/ 27, /* reset=*/ 14);
  u8g2.begin();
  u8g2.enableUTF8Print();	
  const char str[] = "你好你好你好你好11112";		// Chinese "Hello World"
  for(;;)
  {
    show_to_screen(u8g2, str, u8g2_font_wqy16_t_chinese2, 0, 0);
    vTaskDelay(2000);
  }
}


/**
 * 在OLED显示屏上显示文字
 * 
 * @param u8g2 显示屏对象，用于操作SSD1306型128x64分辨率的OLED显示屏
 * @param str 要显示的字符串常量
 * @param font 字体常量指针，用于指定显示字符串时所用的字体大小，对应的是不同的字体库
 *    u8g2_font_unifont_t_chinese2 
      u8g2_font_wqy12_t_chinese2
      u8g2_font_wqy13_t_chinese2
      u8g2_font_wqy14_t_chinese2
      u8g2_font_wqy15_t_chinese2
      u8g2_font_wqy16_t_chinese2
      u8g2_font_boutique_bitmap_7x7_t_chinese2
      u8g2_font_boutique_bitmap_9x9_t_chinese2
      u8g2_font_boutique_bitmap_9x9_bold_t_chinese2
 * @param x 字符串显示的起始X坐标
 * @param y 字符串显示的起始Y坐标
 */
void show_to_screen(U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2, const char *str, const uint8_t  *font, int x, int y)
{ 
  int16_t len = strlen(str);
  u8g2.setFont(font);  // use chinese2 for all the glyphs of "你好世界"
  u8g2.setFontDirection(2);
  u8g2.clearBuffer();
  u8g2.setCursor(SCREEN_WIDTH - x, SCREEN_HEIGHT - y - 16);
  u8g2.print(str);		// Chinese "Hello World"
  u8g2.sendBuffer();

}
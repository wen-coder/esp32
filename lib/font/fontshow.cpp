#include <fontlibrary.h>

#include <U8g2lib.h>
void testdrawbitmap(void);
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
//   OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
void show_to_screen(U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2, char *str,  enum show_position x, int row);


void task_show_font_(void *pvParameters) {
  U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 25, /* data=*/ 13, /* cs=*/ 26, /* dc=*/ 27, /* reset=*/ 14);
  u8g2.begin();
  u8g2.enableUTF8Print();	
  u8g2.setFont(u8g2_font_wqy14_t_chinese2);  
  u8g2.setFontDirection(2);
  char str[] = "你好你好你好你好";		// Chinese "Hello World"
  for(;;)
  {
    log_i("task_show_font_");
    u8g2.clearBuffer();
    show_to_screen(u8g2, str, mid, 1);
    vTaskDelay(500);
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
      u8g2_font_wqy14_t_chinese2  （暂定该字体，14x14的大小，当字体大小为14时，显示效果最好可以显示四行，并且可以显示框框）
      u8g2_font_wqy15_t_chinese2
      u8g2_font_wqy16_t_chinese2
      u8g2_font_boutique_bitmap_7x7_t_chinese2
      u8g2_font_boutique_bitmap_9x9_t_chinese2
      u8g2_font_boutique_bitmap_9x9_bold_t_chinese2
 * @param x 字符串显示的起始X坐标
 * @param y 字符串显示的起始Y坐标
 * 使用 strlen 函数计算字符串的长度，注意这里返回的长度是字节数，而不是字符个数。在 UTF - 8 编码下，由于一个中文字符通常占 3 个字节，
 */
void show_to_screen(U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2, char *str,  enum show_position x, int row)
{ 
 
  uint16_t len = strlen(str) / 3;
  // log_i("show_to_screen, show_str.len = %d,\n", len);
  switch (x)
  {  
    case mid:
      u8g2.setCursor(SCREEN_WIDTH - ((SCREEN_WIDTH - (15 * len)) / 2), SCREEN_HEIGHT - 16);
      u8g2.print(str);
      break;
    case left:
      u8g2.setCursor(SCREEN_WIDTH, SCREEN_HEIGHT - ((row + 1) * 16));
      u8g2.print(str);
      break;
    case right:
      u8g2.setCursor(SCREEN_WIDTH - (14 * (9-len)), SCREEN_HEIGHT - ((row + 1) * 16));
      u8g2.print(str);
      break;
    default:
      break;
  }
  u8g2.sendBuffer();
}



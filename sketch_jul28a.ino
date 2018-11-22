
#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1607_200X200_F_4W_SW_SPI u8g2(U8G2_R2, /* clock=*/ D5, /* data=*/ D7, /* cs=*/ D8, /* dc=*/ D6);  // eInk/ePaper Display

// Sources:
// https://github.com/olikraus/u8g2/wiki/gallery#5-feb-2017-ssd1607-200x200-eink
// https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// https://github.com/olikraus/u8g2/wiki/fntlistall#20-pixel-height

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.setPowerSave(0);  // before drawing, enable charge pump (req. 300ms)
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_fub11_tf);
  u8g2.setDrawColor(1);
  u8g2.drawStr( 4, 20, "@pauls_3d_things");
  u8g2.drawStr( 4, 40, "200x200 e-ink on D1 mini");
  u8g2.drawStr( 4, 60, "VCC -> 3V3");
  u8g2.drawStr( 4, 80, "GND -> GND");
  u8g2.drawStr( 4, 100, "D/C -> D6");
  u8g2.drawStr( 4, 120, "SDI -> D7");
  u8g2.drawStr( 4, 140, "CS  -> D8");
  u8g2.drawStr( 4, 160, "CLK -> D5");
  u8g2.drawStr( 4, 180, "U8G2 library");
  
  u8g2.sendBuffer();
  u8g2.setPowerSave(1);  // set power save mode: disable charge pump

  // delay between each page
  delay(10000);

}

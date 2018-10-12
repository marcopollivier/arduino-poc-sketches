#include "U8glib.h"
//#include "DateTime.h"
//#include "DateTimeStrings.h"

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC
 
void draw() 
{
  //Comandos graficos para o display devem ser colocados aqui
 
  
  //Temperatura 
  u8g.setFont(u8g_font_8x13B);
  u8g.drawStr(5, 30, "23");
  //u8g.drawCircle(28,8,3);
  u8g.drawCircle(28,22,3);
  u8g.drawStr(34, 30, "C");

  //Hora
  u8g.setFont(u8g_font_8x13B);
  u8g.drawStr(5, 15, "09:35");
  
  //Texto - AM
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr(47, 15, "AM");

  
}

//moldura relogio
void molduraRelogio() {
  u8g.drawRFrame(0,18, 128, 46, 4);
}

void setup(void) 
{
  Serial.begin(9600);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}
 
void loop(void) 
{
  u8g.firstPage();  
  do
  {
    draw();
  } while( u8g.nextPage() );
   
  delay(50);
}

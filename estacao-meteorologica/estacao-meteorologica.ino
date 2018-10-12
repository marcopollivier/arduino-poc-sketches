//#include "DateTime.h"
//#include "DateTimeStrings.h"

#include "U8glib.h" //responsavel por escrever no monitor

#include "DHT.h" //responsavel por identificar a temperatura pelo sensor
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC
DHT dht(DHTPIN, DHTTYPE);

void draw() {
  drawTemperature();
  drawHour();  
}

void drawHour() {
  //Hora
  u8g.setFont(u8g_font_8x13B);
  u8g.drawStr(5, 15, "09:35");
  
  //Texto - AM
  u8g.setFont(u8g_font_5x7);
  u8g.drawStr(47, 15, "AM");
}


void drawTemperature() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(t) || isnan(h)) {
      Serial.println("Failed to read from DHT");
  } else {
    
    Serial.print(" [Temperatura]: ");
    Serial.print(t);
    Serial.println("°C");
    
    Serial.print(" [Umidade]: ");
    Serial.print(h);
    Serial.print("%"); 

    u8g.setFont(u8g_font_8x13B);
    u8g.drawStr(5, 30, "21");     
    u8g.drawCircle(28,22,3);
    u8g.drawStr(34, 30, "C");  
  }
    
  
}

void setup(void) {
  Serial.begin(9600);
  
  dht.begin();
  
  if (u8g.getMode() == U8G_MODE_R3G3B2) {
    u8g.setColorIndex(255);     // white
  }
  else if (u8g.getMode() == U8G_MODE_GRAY2BIT) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if (u8g.getMode() == U8G_MODE_BW) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
}
 
void loop(void) 
{
  u8g.firstPage();  
  
  do {
    draw();
  } while( u8g.nextPage() );
   
  delay(50);
}

//Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  
#include "U8glib.h"


U8GLIB_SH1106_128X64 u8g(4, 5, 6, 7);  // SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new blue HalTec OLED)

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

void setup(void) {

  // flip screen, if required
  //u8g.setRot180();

  /*
  ### Available methods:
  
  u8g.setRGB(255,255,255);
  u8g.drawPixel(g, r);
  u8g.drawTriangle(14,7, 45,30, 10,40);
  u8g.drawLine(7+a*4, 10, 100, 55);
  u8g.drawBox(10+a,15,30,7);
  u8g.drawDisc(24+a,16,7);
  u8g.drawCircle(24+a,16+30,7);
  u8g.drawRFrame(5, 10,40,30, a+1);
  u8g.drawRBox(50, 10,25,40, a+1);
  u8g.drawStr90(30,31+a, " 90");
  u8g.drawStr180(30-a,31, " 180");
  u8g.drawStr270(30,31-a, " 270");
  
  */
  
  pinMode(13, OUTPUT);           
  digitalWrite(13, HIGH);
  
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop(void) {
  
  // picture loop  
  u8g.firstPage(); 
  do {
    u8g_prepare();
  //u8g.drawCircle(24,16+30,7);
  u8g.drawStr90(50,20, "Nname ");
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1007);
  // Comment 0
  // Comment 1
/*
  int var4 = digitalRead( 4 );
  int var5 = digitalRead( 5 );
  int var6 = digitalRead( 6 );
  int var7 = digitalRead( 7 );
  Serial.print( "var4 = " );
  Serial.println( var4 );
  Serial.print( "var5 = " );
  Serial.println( var5 );
  Serial.print( "var6 = " );
  Serial.println( var6 );
  Serial.print( "var7 = " );
  Serial.println( var7 );*/

}

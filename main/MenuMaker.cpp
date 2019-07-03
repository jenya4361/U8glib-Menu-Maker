// MenuMaker realization
#include "MenuMaker.h"

static U8GLIB_SH1106_128X64 u8g(4, 5, 6, 7);  // SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new blue HalTec OLED)

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

MenuMaker::MenuMaker()
  : m_timer( 0.0f )
  , m_oldTime( 0 )
  , m_updateEveryMS( 1000 )
{
  
}

MenuMaker::init()
{
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
}

MenuMaker::update(unsigned long msFromStart)
{
  unsigned long currentTime = msFromStart;
  unsigned long deltaTimeMS = currentTime - m_oldTime;
  m_oldTime = currentTime;

  // rebuild the picture after some delay
  if( m_timer <= 0.0f )
  {
    // picture loop  
    u8g.firstPage(); 
    do {
      u8g_prepare();
      u8g.drawLine(0, 0, 0, 64);
      // u8g.drawLine(127, 1, 127, 64);
      //u8g.drawLine(0, 0, 128, 1);
      //u8g.drawLine(0, 64, 128, 128);
      //u8g.drawCircle(64,32,7);
      //u8g.drawStr90(50,20, "Hello");
    } while( u8g.nextPage() );

    m_timer = (float)m_updateEveryMS / 1000.0f;
  }

  
  m_timer -= float(deltaTimeMS) / 1000.0f;
}


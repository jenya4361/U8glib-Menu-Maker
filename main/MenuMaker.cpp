// MenuMaker realization
#include "MenuMaker.h"

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
  , m_windowWidth( 128 )
  , m_windowHeight( 64 )
{
  
}

void MenuMaker::init( int w, int h )
{
  // Init Frame
  setWindowSize( w, h );
  m_linesArray.push_back(FourData( 0, 0, 0, h ));
  m_linesArray.push_back(FourData( w, 0, w, h ));
  m_linesArray.push_back(FourData( 0, h, w, h ));
  m_linesArray.push_back(FourData( 0, 0, w, 0 ));
  
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

void MenuMaker::update(unsigned long msFromStart)
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

      for( int i = 0; i < m_linesArray.size(); i++ )
        u8g.drawLine( m_linesArray[i].d1, m_linesArray[i].d2, m_linesArray[i].d3, m_linesArray[i].d4 );

      for( int i = 0; i < m_scenes.size(); i++ )
      {
        Scene& scene = m_scenes[i];
        if( scene.isActive() )
        {
          const mm::Vector< ButtonData >& buttons = scene.getButtons();
          for( int but_i = 0; but_i < m_scenes.size(); but_i++ )
          {
            const ButtonData& bData = buttons[but_i];
            const char* text = bData.first.getText();
            const FourData& coords = bData.first.getCoords();
            
            u8g.drawFrame(coords.d1, coords.d2, coords.d3, coords.d4);
            u8g.drawStr180(coords.d1 + coords.d3/2, coords.d2 + coords.d4 / 2, text);
          }
          
        }
      }
        
      //u8g.drawCircle(64,32,7);
      //u8g.drawStr90(50,20, "Hello");
    } while( u8g.nextPage() );

    m_timer = (float)m_updateEveryMS / 1000.0f;
  }

  
  m_timer -= float(deltaTimeMS) / 1000.0f;
}

void MenuMaker::createScene( const char* name )
{
  Scene newScene( name );
  m_scenes.push_back( newScene );
}
void MenuMaker::showScene( const char* name )
{
  Scene& oldScene = getScene( m_activeSceneName );
  oldScene.setActive( false );
    
  Scene& currentScene = getScene( name );
  currentScene.setActive( true );
}
void MenuMaker::hideScene( const char* name )
{
  Scene& oldScene = getScene( name );
  oldScene.setActive( false );
}

Scene& MenuMaker::getScene( const char* name )
{
  static Scene nullData;
  for( int i = 0; i < m_scenes.size(); i++ )
  {
    Scene& scene = m_scenes[i];
    if( scene.getName() == name )
      return scene;
  }

  return nullData;  
}

// MenuMaker realization
#include "MenuMaker.h"

void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop();
}

MenuMaker* MenuMaker::instance = new MenuMaker();

MenuMaker::MenuMaker()
  : m_timer( 0.0f )
  , m_oldTime( 0 )
  , m_updateEveryMS( 1000 )
  , m_windowWidth( 128 )
  , m_windowHeight( 64 )
  , m_activeScene( 0 )
{
  
}

void MenuMaker::init( int w, int h )
{
  // Init Frame
  setWindowSize( w, h );
    
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

  // Rebuild the picture after some delay
  if( m_timer <= 0.0f )
  {
    render();
    m_timer = (float)m_updateEveryMS / 1000.0f;
  }

  m_timer -= float(deltaTimeMS) / 1000.0f;
}

void MenuMaker::render()
{
    u8g.firstPage(); 
    do {
      u8g_prepare();

      if( m_activeScene && m_activeScene->isActive() )
      {
        Scene* scene = m_activeScene;
        
        // Draw Scene Name
        String sceneName = "-- " + String( scene->getName() ) + " --";
        int sceneNameX = ( m_windowWidth / 2 ) - u8g.getStrWidth(sceneName.c_str()) / 2;
        u8g.drawStr( sceneNameX, 3, sceneName.c_str() );
        
        // Draw Frame
        const Rect& frame = scene->getFrameRect();
        u8g.drawFrame( frame.x, frame.y, frame.width, frame.height );

        // Draw Buttons
        const mm::Vector< ButtonData >& buttons = scene->getButtons();
        for( int but_i = 0; but_i < buttons.size(); but_i++ )
        {
          const ButtonData& bData = buttons[but_i];
          String text = bData.first.getText();
          const Rect& rect = bData.first.getRect();
          
          u8g.drawFrame(rect.x, rect.y, rect.width, rect.height);
          u8g.drawStr(rect.x + 3, rect.y + rect.height/4, text.c_str());
        }
      }
    } while( u8g.nextPage() );  
}

Scene* MenuMaker::createScene( const char* name )
{
  Scene* newScene = new Scene( name );
  newScene->addFrame( m_windowWidth, m_windowHeight );
  m_scenes.push_back( newScene );

  return newScene;
}

void MenuMaker::showScene( const char* name )
{
  if( m_activeScene )
    m_activeScene->setActive( false );
    
  Scene* currentScene = getScene( name );
  currentScene->setActive( true );
  m_activeScene = currentScene;
}

void MenuMaker::hideScene( const char* name )
{
  Scene* scene = getScene( name );
  scene->setActive( false );
}

Scene* MenuMaker::getScene( const char* name )
{
  Scene* nullData = 0;
  for( int i = 0; i < m_scenes.size(); i++ )
  {
    Scene* scene = m_scenes[i];
    if( scene->getName() == name )
      return scene;
  }

  return nullData;  
}

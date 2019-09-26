//Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
#include "U8glib.h"
#include "Scene.h"

static U8GLIB_SH1106_128X64 u8g(4, 5, 6, 7);  // SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new blue HalTec OLED)

// #TODO: add getters
class MenuMaker
{
  private:
    static MenuMaker* instance;

  public: 
    static MenuMaker* Instance()
    {
      return instance;
    }
    
  private:
    MenuMaker();

  public:
    void init( int w, int h );
    void update(unsigned long msFromStart);

  public:
    void setUpdateTimeMS( unsigned long ms ) { m_updateEveryMS = ms; }
    void setWindowSize( int w, int h ) { m_windowWidth = w; m_windowHeight = h; }

  public:
    Scene* createScene( const char* name );
    void showScene( const char* name );
    void hideScene( const char* name );
    Scene* getScene( const char* name );

  private:
    void render();
    

  private:
  
    unsigned long m_updateEveryMS;
    float m_timer;
    unsigned long m_oldTime;
    
    int m_windowWidth;
    int m_windowHeight;

    mm::Vector<Scene*> m_scenes;
    Scene* m_activeScene;
};

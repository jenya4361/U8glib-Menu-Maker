//Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
#include "U8glib.h"
#include "Scene.h"

// #TODO: add getters
class MenuMaker
{
  public:
    MenuMaker();

  public:
    init( int w, int h );
    
    update(unsigned long msFromStart);

  public:
    void setUpdateTimeMS( unsigned long ms ) { m_updateEveryMS = ms; }
    
    void setWindowSize( int w, int h ) { m_windowWidth = w; m_windowHeight = h; }

  public:
    void createScene( const String& name );
    void showScene( const String& name );
    void hideScene( const String& name );
    
    Scene& getScene( const String& name );
    

  private:
  
    unsigned long m_updateEveryMS;
    float m_timer;
    unsigned long m_oldTime;
    
    int m_windowWidth;
    int m_windowHeight;

    mm::Vector<Int4Data> m_linesArray;
    mm::Vector<Scene> m_scenes;
    String m_activeSceneName;
};

static MenuMaker Menu;


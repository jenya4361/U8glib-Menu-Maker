//Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
#include "U8glib.h"

class MenuMaker
{
  public:
    MenuMaker();

  public:
    init();
    
    update(unsigned long msFromStart);

  public:
    void setUpdateTimeMS( unsigned long ms ) { m_updateEveryMS = ms; }

  private:
    unsigned long m_updateEveryMS;
    float m_timer;
    unsigned long m_oldTime;
};

static MenuMaker Menu;


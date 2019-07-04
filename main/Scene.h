#include "Button.h"

using ButtonData = MMPair< Button, void (*)() >;

class Scene
{
  public:
    Scene();
    Scene( const String& name );
    Scene( const Scene& scene );
  
  public:
    void addButton( const String& name, void (*callback)() );

    const String& getName() const { return m_name; }
    const mm::Vector< ButtonData >& getButtons() const { return m_buttons; }

    void setActive( bool active ) { m_isActive = active; }
    bool isActive() const { return m_isActive; }

  private:
    String m_name;
    mm::Vector< ButtonData > m_buttons;

    int m_nextY;

    bool m_isActive;
};


#include "Button.h"

using ButtonData = MMPair< Button, void (*)() >;

class Scene
{
  public:
    Scene();
    Scene( const char* name );
    Scene( const Scene& scene );
  
  public:
    void addButton( const char* name, void (*)() );

    inline const char* getName() const { return m_name; }
    inline const mm::Vector< ButtonData >& getButtons() const { return m_buttons; }

    void setActive( bool active ) { m_isActive = active; }
    inline bool isActive() const { return m_isActive; }

    void addFrame( int w, int h );
    inline const Rect& getFrameRect() const { return m_frame; }

    void setCursorButtonIndex( int buttonIndex );
    void cursorUp();
    void cursorDown();
    void pressCurrentButton();

  private:
    const char* m_name;
    Rect m_frame;
    mm::Vector< ButtonData > m_buttons;

    int m_nextY;
    bool m_isActive;
    int m_currentCursorIndex;
};

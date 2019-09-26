#include "ProjectData.h"
#include "mmvector.h"
#include <Arduino.h>

class Button
{
  public:

    Button()
      : m_textInside( "" )
      , m_additionalText( "" )
    {}
  
    void setText( const char* text ) { m_textInside = text; }
    String getText() const { return String(String(m_textInside) + String(m_additionalText)); }
    void setAdditionalText( const char* text ) { m_additionalText = text; }

    void setCoords( const Rect& data ) { m_boxData = data; }
    inline const Rect& getRect() const { return m_boxData; }
  
  private:
    Rect m_boxData;
    const char* m_textInside;
    const char* m_additionalText;
};

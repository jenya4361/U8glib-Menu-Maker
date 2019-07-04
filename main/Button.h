#include "ProjectData.h"

class Button
{
  public:
    void setText( const String& text ) { m_textInside = text; }
    const String& getText() const { return m_textInside; }

    void setCoords( const Int4Data& data ) { m_boxData = data; }
    const Int4Data& getCoords() const { return m_boxData; }
  
  private:
    Int4Data m_boxData;
    String m_textInside;
};


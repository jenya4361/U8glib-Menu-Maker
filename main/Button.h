#include "ProjectData.h"
#include "mmvector.h"

class Button
{
  public:
  
    void setText( const char* text ) { m_textInside = text; }
    const char* getText() const { return m_textInside; }

    void setCoords( const FourData& data ) { m_boxData = data; }
    const FourData& getCoords() const { return m_boxData; }
  
  private:
    FourData m_boxData;
    const char* m_textInside;
};

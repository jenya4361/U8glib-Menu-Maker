template< class T1, class T2 >
struct MMPair
{
  MMPair(){}
  MMPair(const T1& _first, const T2& _second)
    : first( _first )
    , second( _second )
  {}
  
  T1 first;
  T2 second;
};

struct Rect
{
    int x, y, width, height;

    Rect() {}

    Rect( const Rect& rect )
      : x( rect.x )
      , y( rect.y )
      , width( rect.width )
      , height( rect.height )
    {}

    Rect(int _x, int _y, int _width, int _height)
      : x( _x )
      , y( _y )
      , width( _width )
      , height( _height )
    {}
};

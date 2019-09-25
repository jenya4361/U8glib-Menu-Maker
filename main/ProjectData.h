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

struct FourData
{
    int d1;
    int d2;
    int d3;
    int d4;

    FourData() {}

    FourData( const FourData& fData )
    {
      d1 = fData.d1;
      d2 = fData.d2;
      d3 = fData.d3;
      d4 = fData.d4;
    }

    FourData(int _d1, int _d2, int _d3, int _d4)
      : d1( _d1 )
      , d2( _d2 )
      , d3( _d3 )
      , d4( _d4 )
    {

    }
};

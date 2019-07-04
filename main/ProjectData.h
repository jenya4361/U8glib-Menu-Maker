#include "mmvector.h"

struct Int4Data
{
  Int4Data(int _v1, int _v2, int _v3, int _v4)
    : v1( _v1 )
    , v2( _v2 )
    , v3( _v3 )
    , v4( _v4 )
  {}
  
  int v1, v2, v3, v4;
};

template< typename T1, typename T2 >
struct MMPair
{
  MMPair(const T1& _first, const T1& _second)
    : first( _first )
    , second( _second )
  {}
  
  T1 first;
  T2 second;
};


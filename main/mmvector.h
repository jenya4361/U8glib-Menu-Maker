namespace mm
{  
  const short kStandartVectorInitSize = 10;
  template<class T> 
  class Vector 
  {    
    public:
      Vector( const Vector& vec ) : m_reserve( vec.m_reserve ), m_size( vec.m_size ) { m_elems = vec.m_elems; }
      Vector() : m_reserve( kStandartVectorInitSize ), m_size( 0 ) { m_elems = new T[kStandartVectorInitSize]; }
      Vector( const int s ) : m_reserve( s ), m_size( 0 ) { reserve(s); }
      Vector& operator=( const Vector& );
      ~Vector() { delete m_elems; }
      T& operator[](int n) { return m_elems[n]; }
      const T& operator[](int n) const { return m_elems[n]; }
      inline int size() const { return m_size; }
    
      void reserve(int newSize);
      void push_back(const T& val);
      T& back();

    private:
      int m_size;
      int m_reserve;
      T* m_elems;
  };
  
  template<class T> 
  Vector<T>& Vector<T>::operator=(const Vector& a) {

  }
  
  template<class T> 
  void Vector<T>::reserve(int newSize)
  {
    T* temp = new T[newSize];
    for( int i = 0; i < m_reserve; i++ )
      temp[i] = m_elems[i];

    delete m_elems;

    m_reserve = newSize;
    m_elems = temp;
  }
  
  template<class T> 
  void Vector<T>::push_back(const T& val)
  {
    if( m_size + 1 >= m_reserve )
    {
      reserve( m_reserve + kStandartVectorInitSize );
    }

    m_elems[m_size++] = val;
  }
  
  template<class T> 
  T& Vector<T>::back()
  {
    return m_elems[m_size];
  }
}

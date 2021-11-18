#include<iostream>

const int _DEFAULT_VECTOR_SIZE = 4;
using std::cout;
using std::endl;

template <typename T>
class vector
{
   public :

      // constructors
      vector()
         : array_( new T[_DEFAULT_VECTOR_SIZE] ),
         reserved_size_( _DEFAULT_VECTOR_SIZE ),
         size_( 0 )
         { }

      vector(int n) // create vector with n default elements
         : array_( new T[n] ),
         reserved_size_( n ),
         size_( 0 )
         { }

      // destructor
      ~vector()
      { delete[] array_; }

      T* begin();
      T* end();
      void push_back(const T &t);
      void resize(int n);

   private :

      // iterator
      T *array_;
      int size_;
      int reserved_size_;
};


// an auto pointer to use with arrays
// lets use arrays in create temp and swap idiom
template <typename T> 
class auto_array
{
   public :
      auto_array(T *t) : ptr_( t )
      { }

      ~auto_array()
      { delete[] ptr_; }

      T *operator->()
      { return ptr_; }

      T *release()
      { 
         T *tmp( ptr_ );
         ptr_ = 0;
         return tmp;
      }

      T &operator[](int i)
      { return ptr_[i]; }

   private :
      T *ptr_;
};

template <typename T>
class reverse_iterator
{
   public:
      reverse_iterator(T *p)
         : pos(p) { }

      reverse_iterator()
         : pos(0) { }

      T operator*()
      { return *pos; }

      T *operator-()
      { return pos; }

      reverse_iterator operator++(int)
      { pos--; return *this; }

      reverse_iterator operator--(int)
      { pos++; return *this; }

      bool operator!=(const reverse_iterator rhs)
      { return this.pos != rhs.pos; }

   private:
      T *pos;
};



template <typename T>
void vector<T>::push_back(const T &t)
{
   // if we've run out of space, allocate more memory
   if(size_ == reserved_size_)
      resize(reserved_size_ + _DEFAULT_VECTOR_SIZE);

   // size_ when used as an index, points to the next position after
   // the last element in the vector
   array_[size_] = t;

   // now there is one more element in the vector, so increase the size
   size_++;
}


template <typename T>
void vector<T>::resize(int n) // make the size of the internal array exactly n
{
   if(n > reserved_size_) // if requested size is more than the current size
   {
      // allocate a new array of larger capacity
      // copy the old array to new array
      // destroy old array
      auto_array<T> new_array( new T[n] );
      for(int i=0; i<size_; i++)
      {
         new_array[i] = array_[i];
      }

      delete[] array_;
      array_ = new_array.release();
      reserved_size_ = n;
   }
}

// iterator functions
template <typename T>
T* vector<T>::begin()
{ return array_; }

template <typename T>
T* vector<T>::end()
{ return array_ + size_; }

int main()
{
   vector<int> first(5);
   first.push_back(1);
   first.push_back(2);
   first.push_back(3);
   first.push_back(4);

   cout <<*(first.begin()) << endl; 
   cout <<*(first.begin()+1)<< endl;
   cout <<*(first.begin()+2)<< endl;
   cout <<*(first.begin()+3)<< endl;

   return 0;
}

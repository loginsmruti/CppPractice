#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class DynamicArray
{
   public:
      DynamicArray(){};

      DynamicArray(int rows, int cols): dArray(rows, vector<T>(cols)){}

      vector<T> & operator[](int i) 
      {
         return dArray[i];
      }
      const vector<T> & operator[] (int i) const 
      {
         return dArray[i];
      }
      void resize(int rows, int cols)//resize the two dimentional array .
      {
         dArray.resize(rows);
         for(int i = 0;i < rows;++i) dArray[i].resize(cols);
      }
   private:
      vector<vector<T> > dArray;  
};

void Matrix(int x, int y)
{
   DynamicArray<int> my2dArr(x, y);
   my2dArr[0][0] = 1;
   my2dArr[0][1] = 2;
   my2dArr[0][2] = 3;
   my2dArr[1][0] = 4;
   my2dArr[1][1] = 5;
   
   cout <<  my2dArr[0][0] << endl;
   cout <<  my2dArr[0][1] << endl;
   cout <<  my2dArr[0][2] << endl;
   cout <<  my2dArr[1][0] << endl;
   cout <<  my2dArr[1][1] << endl;
}

int main()
{
   Matrix(3,3);
   return 0;
}

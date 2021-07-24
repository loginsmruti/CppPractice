#include <iostream>
#include <valarray>
#include <cmath>

using namespace std;

int main()
{
   valarray<int> v(10);

   for(int i=0; i<10; i++)
      v[i] = i;

   cout << "Original contents: ";
   for(int i=0; i<10; i++)
      cout << v[i] << " \n\n";

   valarray<int> result = v[slice(0,5,2)];

   cout << "Contents of result: ";
   for(int i=0; i<result.size(); i++)
      cout << result[i] << " ";

   cout << endl;

   return 0;
}

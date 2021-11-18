#include <bitset>
#include <iostream>

using namespace std;

int main( )
{
   const int num_lights = 15;
   const bitset<num_lights> outside( 0xf );
   const bitset<num_lights> inside( 0xff0 );
   const bitset<num_lights> driveway( 0x7000 );

   bitset<num_lights> lights;

   for( int i = 0; i < num_lights; i +=2 )
      lights.reset( i );
   cout << lights;

   return 0;
}

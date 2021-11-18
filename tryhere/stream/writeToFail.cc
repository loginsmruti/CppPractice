#include <fstream>
#include <iostream>
#include <cstdlib> // for exit()

int main()
{
   using namespace std;

   // ofstream is used for writing files
   // We'll make a file called Sample.dat
   ofstream outf("Rocky.dat");

   // If we couldn't open the output file stream for writing
   if (!outf)
   {
      // Print an error and exit
      cerr << "Uh oh, Sample.dat could not be opened for writing!" << endl;
      exit(1);
   }

   // We'll write two lines into this file
   outf << "first line is written to file" << endl;
   outf << "second line is written to file " << endl;

   return 0;

   // When outf goes out of scope, the ofstream
   // destructor will close the file
}

#include<iostream>
#include <fstream>      // std::fstream
int main ()
{
   using namespace std;
   char p[80];
   fstream file("text1.txt",ios::out|ios::in);
   cout<<"Starting position of the file is "<<file.tellg()<<endl;
//   getch();
   if(file.is_open())
      cout<<"file is openn";
   else
      cout<<"file is not openn";
//   getch();

   file<<"Hello man how are you";
   file.seekp(0);
   while(!file.eof())
   {
      file>>p;
      cout<<p<<endl;
   }
   cout<<"nThe current position of the file pointer is "<<file.tellg();
   file.seekp(0);
   if(file.eof())
      cout<<"nAt the eof";
   while(!file.eof())
   {
      file>>p;
      cout<<p<<endl;
   }
   file.close();
   return 0;
}

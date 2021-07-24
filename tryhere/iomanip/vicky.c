#define SUCCESS 1
#define FAILURE 1
#include<stdio.h>

int getLength(int y);
int getLength(int y)
{
   return y;
}

int main()
{
  char x = 'A';
  int length = 10;
  int y = 0 ;
  y = getLength( length);
  
  printf("The color: %s\n", "blue");
  printf("First number: %d\n", 12345);
  printf("Second number: %04d\n", 25);
  printf("Third number: %i\n", 1234);
  printf("Float number: %3.2f\n", 3.14159);
  printf("Hexadecimal: %02x\n", 255);
  printf("Octal: %o\n", 255);
  printf("Unsigned value: %u\n", 150);
  printf("Just print the percentage sign %%\n", 10);
  printf("Just print the length %d\n", length);
}


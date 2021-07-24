#include<stdio.h>
#include<stdarg.h>

void show(char * ,...);

void show(char *ch , ...)
{
 char *o;
 va_list p;
 va_start(p,ch);
 
 while((o = va_arg(p ,char*)) != 0)
   printf(" %s ",o);
 
}

int main()
{
 show("vicky","rocky","test","me");
 return (0);
}

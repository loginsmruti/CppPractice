#include <stdio.h>                        //HEADER FILES
#include <malloc.h>
#include <string.h>

char *i_to_a(int);
int no_of_digits(int);
char  *generateId(int);


int no_of_digits(int num)
{
    int digit_count = 0; 	

    while(num > 0)
    {
        digit_count++;
        num /= 10;
    }

    return digit_count;
}

char *i_to_a(int num)
{
    char *str;
    int digit_count = 0;

    if(num < 0)
    {
        num = -1*num;
        digit_count++;
    }

    digit_count += no_of_digits(num);   
    str = malloc(sizeof(char)*(digit_count+1));

    str[digit_count] = '\0';

    while(num > 0)
    {
        str[digit_count-1] = num%10 + '0';
        num = num/10;
        digit_count--;
    }

    if(digit_count == 1)
        str[0] = '-';

    return str;
}


char *generateId(int count)
{
      char name[10]="EMP_";
       int i=0 ,j=0;
      //char *con;
       //con = name;
	char *str = i_to_a(count);
         //printf("%s %s",str , strcat(name,str));        
   return strcat(name,str);
}


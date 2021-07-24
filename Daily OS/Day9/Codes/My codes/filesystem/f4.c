#include<stdio.h>



struct s{
   int x,y;
   char arr[10];
   char ch;
 };

 int main()
{
   struct s var1={10,100,"abcd",'x'},var2;
  int  fd=open("new",O_WRONGLY|O_CREATE,S_IRUSR|S_IWUSR);

   write(fd,&var1,sizeof(struct s));
   close(fd);

  fd=open("new",O_RDONLY);
   read(fd,&var2,sizeof(struct s));
    printf("%d\n",var2.x);

return 0;

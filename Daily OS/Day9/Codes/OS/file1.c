#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
struct s
{
    int x,y;
    char arr[5];
    char ch;
};
int main()
{
    struct s s1={20,30,"sam",'s'};
    int fp=open("abc",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR );
    write(fp,&s1,sizeof(struct s));
    close(fp);
    fp=open("abc",O_RDONLY);

    read(fp,&s1,sizeof(struct s));;
}

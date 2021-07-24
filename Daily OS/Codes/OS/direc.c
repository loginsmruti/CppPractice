#include<stdio.h>
#include<dirent.h>
int main()
{
    DIR *dir;
    char name[25];
    struct dirent *d;
    printf("Enter name of folder\n");
    gets(name);
    dir=opendir(name);
    d=readdir(dir);
    printf("name ..%s\n",d->d_name);
}

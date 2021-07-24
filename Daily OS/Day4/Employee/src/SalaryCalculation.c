#include <stdio.h>                          //HEADER FILES

int generate_DA(int);
int generate_HRA(int);
int generate_CCA(int);
int generate_NetSal(int,int,int,int);

int generate_DA(int sal)
{
 return 0.6*sal;
}

int generate_HRA(int sal)
{
 return 0.3*generate_DA(sal);
}

int generate_CCA(int sal)
{
 return 0.05*sal;
}

int generate_NetSal(int sal , int da , int hra ,int cca)
{
 return sal+da+hra+cca;
}


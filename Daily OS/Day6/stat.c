

 
void bbsr( int c)
{
  int j = 50 ;
 
  c = c + j ;

  c = c + j;  
  printf("\nvalue In bbsr : %d\n",c);
}

int main()
{
 int count = 0;
 bbsr(count);
 printf("\nValue In  main()  = %d\n ",count);
}


char *str_upr(char *str)
{
 char buffer[20];
 char *p = str; 
 int i =0 ;
 
 while(p[i] != '\0')
 {
  buffer[i] = p[i] - 32 ;
  i++; 
 }
 buffer[i] = '\0';
 printf("%s",buffer);
 return buffer;
}			


main()
{
 char buffer[10];
 
// str_upr("vicky"); 

 //strcpy(buffer , str_upr("vicky"));
  printf("\n%s\n",str_upr("vicky"));
}

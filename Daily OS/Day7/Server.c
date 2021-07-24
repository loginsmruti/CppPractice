
#include "structure.h"

int main(void)
{
  int pid1 ;
  char *args[] ={"./ui",NULL };  
  
  pid = fork();

  if(!pid)
    execvp("./ui",args);  
  
  
    
   
 
  return (0) ;
}

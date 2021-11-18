#include <string.h>
#include <stdio.h>

void extractProtocolFromHostName(char* queryName, char** protocolName);


/*
   void extractProtocolFromHostName(char* queryName, char** protocolName)
{
   const char delim[2] = ".";

   if(queryName)
   {
      strncpy( *protocolName , queryName, strlen(queryName)+1);
      strtok(*protocolName , delim);
     *protocolName = strtok( NULL , delim);
   }
}
*/

void extractProtocolFromHostName(char* queryName, char** protocolName)
{
   const char delim[2] = ".";
   char *protocol = NULL;

   if(queryName)
   {
      //strncpy( *protocolName , queryName, strlen(queryName)+1);
      //strtok(*protocolName , delim);
      //*protocolName = strtok( NULL , delim);

      strtok(queryName, delim);
      protocol = strtok( NULL , delim);
      strncpy(*protocolName , protocol , strlen(protocol)+1);
   }
}


int  validateServiceField(char* serviceName  , char* pattern)
{
   if(serviceName == NULL || pattern == NULL)
      return 0 ;
      
      char * ptr = NULL;
      char * matchFound = NULL;
      ptr = serviceName;

      for ( ; *ptr; ++ptr)
         *ptr = tolower(*ptr);

      matchFound = strstr(serviceName , pattern);

      if(matchFound != NULL)
        return 1;
      else
        return 0;
}




int main()
{
   char arr[100] = "_aaa._tcp.diam.test.smruti.com.";

   char arr1[100] = "http+D2S";
   
   char* p = NULL;
   int status = 0; 
   
   p = malloc(35);

  extractProtocolFromHostName(arr, &p); 
//   status = validateServiceField(arr1 , "d2s");
   
   printf("Pattern found :: %s", arr);

   return 0;
}

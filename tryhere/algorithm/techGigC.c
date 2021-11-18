#include <stdio.h>
#include <string.h>

#define ZERO_AS_DIGIT 48
#define NINE_AS_DIGIT 57

#define A_UPPER_CASE_LETTER  65 
#define Z_UPPER_CASE_LETTER   90

#define A_LOWER_CASE_LETTER 97
#define Z_LOWER_CASE_LETTER 122

int validateMsgBuffer(char *msgBuffer , short int msgBufferLength);


int validateMsgBuffer(char *msgBuffer , short int msgBufferLength)
{
   short int statusLength = 0 ;
   short int statusMsg = 0 ;
   short int status = 0 ;

   if(msgBufferLength > 8)
      statusLength = 1;
   
   while( *msgBuffer != '\0')
   {
      if((*msgBuffer < A_UPPER_CASE_LETTER || *msgBuffer > Z_UPPER_CASE_LETTER) &&
         (*msgBuffer < A_LOWER_CASE_LETTER || *msgBuffer > Z_LOWER_CASE_LETTER) &&
         (*msgBuffer <  ZERO_AS_DIGIT || *msgBuffer > NINE_AS_DIGIT)) 
      {
         statusMsg = 1;
         break; 
      }
         
      ++msgBuffer;
   }
   if(statusMsg && statusLength)
   {
      printf("1");
      return 0;
   }
   if( statusMsg )
   {
      printf("Message Error");
      return 0;
   }
   if( statusLength)
   {
      printf("Exceeded Limits");
      return 0;
   }
  return 1; 
}
   
int main(int argc , char*a[])
{
   char msgBuffer[20] = {0};
   char encodedBuffer[20] = {0};

   short int msgBufferLength = 0;
   
   short int status = 0; 
   short int i  = 0; 
   short int j  = 0; 
 
  if(argc != 2 )
    return 0; 
     
   printf("Enter a message : %s",*(a+1) );
   strcpy(msgBuffer , *(a+1)); 
      
//   printf("Enter a message : ");
//   scanf("%s" , msgBuffer);

   msgBufferLength = strlen(msgBuffer) ; 

         
   status = validateMsgBuffer(msgBuffer, msgBufferLength);
   
   //printf("status : %s" ,status ?"TRUE":"FALSE");
   if(!status)
      return 0;

   encodedBuffer[0] = Z_UPPER_CASE_LETTER ;
   encodedBuffer[1] = Z_UPPER_CASE_LETTER;
   encodedBuffer[2] = msgBufferLength + ZERO_AS_DIGIT;

   for ( j = 3 ; i < msgBufferLength; j++ , i++)
   {
      if(msgBuffer[i] == 'Z')
      {
         encodedBuffer[j] = '#';
         encodedBuffer[++j] = ',';
      }
      else
      {
         encodedBuffer[j] = msgBuffer[i];
         encodedBuffer[++j] = ',';
      }
   }
   encodedBuffer[--j] = '!';

   printf("MessageBuffer : %s\n EncodedMessageBuffer :%s\n" , msgBuffer , encodedBuffer);


   return 0;
}

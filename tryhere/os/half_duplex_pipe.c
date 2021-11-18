//program to create a pipe to send an input command string from server to child and the 
// child executes this command
//the string will be read as a command line argument
// this is unidirectional pipe to only send from parent to child not vice versa 
//     ./<program> 
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_BUF         256


int child_process(int readfd)
{
   char buf[MAX_BUF];
   int i;
   size_t bytes_read = 0;

   bzero(&buf[0], sizeof(buf));
   i = 0;
   printf("\n Child :");
   while((read(readfd, &buf[i], 1)) > 0)
   {
      printf("%c",buf[i++]);  
   }
   bytes_read = i;

   printf("\n Child : bytes read:%d", bytes_read);
   //TBD for arguments with spaces need to extract the arguments, options
   // and fill an argv array 
   //execute the command
   execlp(&buf[0], &buf[0], NULL);
   fflush(stdout);
   return 0;
}

int parent_process(int writefd, char *cmd_string)
{
   char buf[MAX_BUF];
   int i;
   //size_t bytes_read = 0;
   size_t bytes_written = 0;

   bzero(&buf[0], sizeof(buf));
   strcpy(&buf[0], cmd_string);

   i = 0;
   printf("\n Parent : to sendbuf:%s",  buf);

   while(i <= strlen(buf))
   {
      write(writefd, &buf[i++], 1);
   }
   bytes_written = i;
   fflush(stdout);

   return 0;

}

int main(int argc, char *argv[])
{
   int pipe1[2];
   pid_t child_pid;
   int status = 0;


   if (argc < 2)
   {
      printf("\n Insufficientm arguments");
      return 0;
   }

   //create a pipes
   if (pipe(pipe1) != 0)
   {
      perror("Pipe error");
      exit(EXIT_FAILURE);
   }

   child_pid = fork();
   if (child_pid < 0)
   {
      //error case
      close(pipe1[1]);
      close(pipe1[0]);
      perror("fork failed");
   }
   else if (child_pid == 0)
   {
      //close unused fd's
      close(pipe1[1]);

      //handle parent message processing separately
      child_process(pipe1[0]);


      close(pipe1[0]);
      _exit(EXIT_SUCCESS);

      return 0;
   }
   else
   {  //parent process
      close(pipe1[0]);

      parent_process(pipe1[1], argv[1]);

      close(pipe1[1]);   //send EOF

      waitpid(child_pid, &status, 0);
      printf("\n Child :%d exited, child status:%d",
            child_pid,  WEXITSTATUS(status));
      printf("\n Parent to exit");
      fflush(stdout);

      return 0;
   }

   return 0;
}

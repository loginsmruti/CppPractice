#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdarg.h>

static void signal_handler(int);
static void dumpstack(void);
static void cleanup(void);
void init_signals(void);
void panic(const char *, ...);

struct sigaction sigact;
char *progname;

int main(int argc, char **argv) {
   char *s;
   progname = *(argv);
   atexit(cleanup);
   init_signals();
   printf("About to seg fault by assigning zero to *s\n");
   *s = 0;
   sigemptyset(&sigact.sa_mask);
   return 0;
}

void init_signals(void) {
   sigact.sa_handler = signal_handler;
   sigemptyset(&sigact.sa_mask);
   sigact.sa_flags = 0;
   sigaction(SIGINT, &sigact, (struct sigaction *)NULL);

   sigaddset(&sigact.sa_mask, SIGSEGV);
   sigaction(SIGSEGV, &sigact, (struct sigaction *)NULL);

   sigaddset(&sigact.sa_mask, SIGBUS);
   sigaction(SIGBUS, &sigact, (struct sigaction *)NULL);

   sigaddset(&sigact.sa_mask, SIGQUIT);
   sigaction(SIGQUIT, &sigact, (struct sigaction *)NULL);

   sigaddset(&sigact.sa_mask, SIGHUP);
   sigaction(SIGHUP, &sigact, (struct sigaction *)NULL);

   sigaddset(&sigact.sa_mask, SIGKILL);
   sigaction(SIGKILL, &sigact, (struct sigaction *)NULL);
}

static void signal_handler(int sig) {
   if (sig == SIGHUP) panic("FATAL: Program hanged up\n");
   if (sig == SIGSEGV || sig == SIGBUS){
      dumpstack();
      //panic("FATAL: %s Fault. Logged StackTrace\n", (sig == SIGSEGV) ? "Segmentation" : ((sig == SIGBUS) ? "Bus" : "Unknown"));

      
      panic("Tlv[2] - GSM_VLR_CAP_CALL_REF_NUM_FIELD: 2416480905854573M:\000\230\234\277\277\003\000\000\000(\000\000\000\034\000\200\245\003\000\000\000\016\000\000\000\026)\342\266H\000\200\245\002(\342\266\360*\342\266\030\000\000\000\070\003\200\245\003\000\000\000\020\000\000\000\020\000\200\245(\000\000\000@\000\200\245\364/\344\266\020\000\200\245p\236\277\277\350\234\277\277\034\030\327\266\355\061\362\237\355\061\362\237\354\061\362\237\364\217\367\266\016\000\000\000p\236\277\277\330\235\277\277\363\360\356\266`\253\367\266\006\000\000\000\000\000\000\000\002\020");
   }
   if (sig == SIGQUIT) panic("QUIT signal ended program\n");
   if (sig == SIGKILL) panic("KILL signal ended program\n");
   if (sig == SIGINT) ;
}

void panic(const char *fmt, ...) {
   char buf[50];
   va_list argptr;
   va_start(argptr, fmt);
   vsprintf(buf, fmt, argptr);
   va_end(argptr);
   fprintf(stderr, buf);
   exit(-1);
}

static void dumpstack(void) {
   /* Got this routine from http://www.whitefang.com/unix/faq_toc.html
    ** Section 6.5. Modified to redirect to file to prevent clutter
    */
   /* This needs to be changed... */
   char gdb[160];

   sprintf(gdb, "echo 'where\ndetach' | gdb -a %d > %s.dump", getpid(), progname);
   /* Change the dbx to gdb */

   system(gdb);
   return;
}

void cleanup(void) {
   sigemptyset(&sigact.sa_mask);
   /* Do any cleaning up chores here */
}



#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#define	KEY	99

main( ) {
	  int	shmid ;	char *shmptr ;
	  shmid = shmget(KEY, 20, IPC_CREAT | 0660) ;
	  shmptr = shmat(shmid, (void *)0, 0) ;
	  sleep(5) ;
	  shmdt(shmptr) ;
}

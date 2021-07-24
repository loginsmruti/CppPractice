 #include "header.h"


#define KEY 100

 ///the lock operation
struct sembuf op_lk[2]={0,0,0, 0,1,0};
//the unlock operation
struct sembuf op_ulk[1]={0, -1, 0};
main()
{
	int semid;
	int pid;
	pid=getpid();
	semid=semget(KEY, 1, IPC_CREAT|0660);
	printf("%d, : before lock\n", pid);
	semop(semid, &op_lk[0],2);
	printf("%d: after lock\n", pid);

//	acess  the shared resource 

	sleep(5);
	printf("%d : before unlock\n", pid);
	semop(semid, &op_ulk[0], 1);
	printf("%d : after unlock\n", pid);

}

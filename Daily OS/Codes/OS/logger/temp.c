#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

struct s {
	int a, b ;
} ;

struct msg {
	long type ;
	struct s m ;
} ;

main() {
	struct msg m, m1 ;
	m.type = 1 ;
	m.m.a = 90 ;
	m.m.b = 190 ;
	int mid = msgget(101, IPC_CREAT|0600) ;
	msgsnd(mid, &m, sizeof(struct s), 0) ;
	msgrcv(mid, &m1, sizeof(struct s), -10, 0) ;
	printf("%d %d\n", m1.m.a, m1.m.b) ;
}

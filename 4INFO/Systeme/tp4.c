#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int init(int i){
	int id = semget(IPC_PRIVATE,1,IPC_CREAT|0666);
	semctl(id,0,SETVAL,i);
	return id;
}

struct sembuf operation;

P(int semid){
	operation.sem_num = 0;
	operation.sem_op = -1;
	operation.sem_flg=0;
	semop(semid,&operation,1);
}

V(int semid){
	operation.sem_num = 0;
	operation.sem_op = 1;
	operation.sem_flg=0;
	semop(semid,&operation,1);
}

int main(int argc, char* argv[]){
	int id = init(1);
	printf("%d\n",id);
	printf("%d\n",semctl(id,0,GETVAL));
	P(id);
	printf("%d\n",semctl(id,0,GETVAL));
	V(id);
	printf("%d\n",semctl(id,0,GETVAL));
	P(id);
	printf("%d\n",semctl(id,0,GETVAL));
	P(id);

/* Résultats
786456
1
0
1
0
*/
	
}

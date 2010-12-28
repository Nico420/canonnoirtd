#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


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
	int id = semget(ftok("test",0),1,0);
	P(id);
	int i=0;	
	for(i=0;i<100;i++)
			
		printf("Pub : %s\n",argv[1]);
	V(id);
}

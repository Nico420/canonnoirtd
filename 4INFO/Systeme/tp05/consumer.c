#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NPLEIN 1
#define NVIDE 2

int consommer(){
	P(semget(ftok("sema",0),1,0),NPLEIN);
	P(mutex);
	/*int idshm = shmget(ftok("mem",0),5*(sizeof(int)),0);
	int shm = shmat(idshm,NULL,0); 
	m = shm[queue];
	queue++;*/
	V(mutex);
}

struct sembuf operation;

P(int semid,int nb){
	operation.sem_num = 0;
	operation.sem_op = -1;
	operation.sem_flg=0;
	semop(semid,&operation,nb);
}

V(int semid, int nb){
	operation.sem_num = 0;
	operation.sem_op = 1;
	operation.sem_flg=0;
	semop(semid,&operation,nb);
}

int main(void){
	consommer();
	return 0;
} 	

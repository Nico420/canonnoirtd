#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define N 5


int main(void){
	int id = semget(ftok("sema",0),3,IPC_CREAT|0666);
	// Init(nplein,0)
	semctl(id,0,SETVAL,1);
	// Init(nvide,N)
	semctl(id,N,SETVAL,2);
	// sémaphore mutex
	semctl(id,0,SETVAL,3);
	//Initialisation de la mémoire partagée
	int shmid = shmget(ftok("mem",0),7*(sizeof(int)),0666|IPC_CREAT);
	
	int* shm= shmat(shmid,NULL,0);
	memset(shm,0,7*(sizeof(int)));
	printf("%ld\n",shm);
	int tete=0;
	int queue=0;
	return id;
}



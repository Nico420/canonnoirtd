#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


int main(void){
	int id = semget(ftok("test",0),1,IPC_CREAT|0666);
	semctl(id,0,SETVAL,1);
	return id;
}

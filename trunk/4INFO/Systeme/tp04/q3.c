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

tri_fusion(int* t,int n){
	if(n>1){
		tri_fusion(t,n/2);
		tri_fusion(t+n/2,n-n/2);
		fusionner(t,n/2,t+n/2,n-n/2);
	}
}

fusionner(int* ad1,int n1,int* ,int* ad2,int n2){
	int i;
	int ind = 0;
	for(i=0;i<n1+n2;i++){
		if(ad[i]>ad[i+n1]){
			int temp = ad[i];
			ad[i] = ad[ind+n1];
			ad[ind+n1] = temp;
		}
	}
}

int main(int argc, char* argv[]){
	
}

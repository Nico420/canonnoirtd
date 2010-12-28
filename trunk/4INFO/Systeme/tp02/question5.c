#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

struct sigaction act;

void handler(int sig){
	printf("handler\n");
}
	
main(void){
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigaction(SIGUSR1,&act,NULL);
	sigaction(SIGUSR2,&act,NULL);
	pid_t pid= fork();
	if (pid!=0){
	    /* ------------ code du père ----------------- */
		int cpt = 10;
		sleep(1);
		while((cpt--)!=0){
			//sleep(1); //1ere solution
			kill(pid,SIGUSR1);
			printf("Envoi par le pere\n");
			pause();
		}
	}
	else{
	    /* ------------ code du fils ----------------- */	    	
		while(1){
			pause();
			printf("Recu par le fils\n");
			kill(getppid(),SIGUSR2);
		
		}
	}
}
	/**/
	

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

struct sigaction act;
pid_t pidFils;
void handler(int sig){
	if(pidFils!=0){
		printf("handler%ld\n",getpid());
int i=0;		
for(i=0;i<10;i++){
	pause();
}	
	}
}
	
main(void){
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigaction(SIGINT,&act,NULL);
	int i=0;
	
	int pere;
	  for(i=0;i<10;i++){
		  if(getppid()!=pere ){
			  pere=getpid();
			  pidFils= fork();
		}
	}
	  if (pidFils!=0){
		  sleep(20);
	  }

	  else{
	    /* ------------ code du fils ----------------- */
	    sleep(1);
	    printf("je suis le fil, mon numero est %d",getpid());
	    printf(", celui de mon pere est %d\n", getppid());
	    sleep(15);
	    }
}
	/**/
	

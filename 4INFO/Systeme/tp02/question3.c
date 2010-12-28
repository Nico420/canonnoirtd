#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

struct sigaction act;
int cpt = 0;
void handler(int sig){
	printf("%d\n",cpt);
}
	
main(void){
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigaction(SIGTSTP,&act,NULL);
		while(1){
			cpt++;
			sleep(1);
		}
}
	/**/
	

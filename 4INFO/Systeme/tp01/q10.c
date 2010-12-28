#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>



main(){
	int i=0;
	pid_t pidFils;
	int pere;
for(i=0;i<2;i++){
	  if(getppid()!=pere ){
		  pere=getpid();
		  pidFils= fork();
		  if(getpid()!=pidFils ){
			pidFils=fork();
		  }
	}
}
    /* ------------ code du père ----------------- */
    printf("mon numero est %d",getpid()); 
    printf(", celui de mon père est %d\n",getppid());
    sleep(1);

}

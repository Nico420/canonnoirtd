#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

main(){
	int i=0;
	pid_t pidFils;
	int pere;
  for(i=0;i<10;i++){
	  if(getppid()!=pere ){
		  pere=getpid();
		  pidFils= fork();
	}
}
  if (pidFils!=0){
	  sleep(15);
  }

  else{
    /* ------------ code du fils ----------------- */
    sleep(1);
    printf("je suis le fil, mon numero est %d",getpid());
    printf(", celui de mon pere est %d\n", getppid());
    sleep(15);
    }
}


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
    /* ------------ code du père ----------------- */
    int i;
    for(i=0;i<10;i++){
      printf("je suis le pere\n");
      sleep(3);
    }

  }
  else{
    /* ------------ code du fils ----------------- */
    int i;
    for (i=0;i<10;i++){
    printf("je suis le fils\n");
    sleep(3);
    }
}
}

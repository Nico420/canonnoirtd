#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

	
main(void){
	int fd[2];
	pipe(fd);
	pid_t pidFils;
	pidFils= fork();
	  if (pidFils!=0){
		/*--------- code du père (serveur) --------*/
		
	  }

	  else{
	    /* ------------ code du fils (client) ----------------- */
	  }
}

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

	
main(int argc, char* argv[]){
	/*char user[60];
	printf("Veuillez indiquer un utilisateur :\n");
	scanf("%s",user);*/
	int fd[2];
	pipe(fd);
	pid_t pidFils;
	pidFils= fork();
	  if (pidFils!=0){
		/*--------- code du père --------*/
	dup2(fd[1],1);		
	execlp("who","who",NULL);
		
	  }

	  else{
	    /* ------------ code du fils ----------------- */
		dup2(fd[0],0);    
		execlp("grep","grep",argv[1],NULL);
	  }
}

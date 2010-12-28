#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>

	
main(void){
	int nb;
	int fd;
	char buf[80];
	if(mkfifo("/tmp/client_pipe",0600) == -1){
		perror("mkfifo");
		exit(1);
	}
	if((fd=open("/tmp/server_pipe",O_WRONLY)) == -1){
		perror("open");
	}			
	write(fd,"Hello",6);
	close(fd);
	
	if((fd = open("/tmp/client_pipe",O_RDONLY)) == -1){
		/*Bloquant*/
		perror("open");
		exit(1);
	}

	nb = read(fd,buf,80);
if(nb>0){
		printf("Message lu : %s\n",buf);
	}
	close(fd);
	return 0;
}

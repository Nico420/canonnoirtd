#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

produire(data m){
	P(nplein);
	P(mutex);
	m:=T[queue];
	queue := queue+1 mod N;
	V(mutex);
	V(nvide);
	return m;
}

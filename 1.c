#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * func(void * args){
	int i;
	for (i=0;i<10;i++){
		fprintf(stderr,"Child thread. Iteration %d\n",i);
		sleep(1);
	}
	return NULL;
}

int main(void){
	pthread_t thread;
	int result;
	result = pthread_create(&thread,NULL,&func,NULL);
	if(result != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	int i;
	for (i=0;i<10;i++){
		fprintf(stderr,"Main thread. Iteration %d\n",i);
		sleep(2);
	}
	return 0;
}

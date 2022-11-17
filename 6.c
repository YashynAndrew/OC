#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int i = 0;

void counter(){
	printf("Amount of iterations: %d\n",i);
}

void * func(void * arg){
	
	pthread_cleanup_push(&counter,NULL);
	while(1){
	fprintf(stderr,"Iteration %d\n",i+1);
	i++;
	sleep(1);}
	pthread_cleanup_pop(0);
	return 0;
}

int main(int argc,const char *argv[]){
	if(argc == 1){
		printf("Nothing here\n");
		return 0;
	}
	
	int time = atoi(argv[1]);
	//int i;
	void* result;
	pthread_t thread;
	pthread_create(&thread,NULL,&func,NULL);
	//
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
	sleep(time);
	pthread_cancel(thread);
	
	if(!pthread_equal(pthread_self(),thread)){
		pthread_join(thread,&result);
	}
	if(result==PTHREAD_CANCELED){
		fprintf(stderr,"Canceled \n");
	}else fprintf(stderr,"NOT Canceled \n");
	
	return 0;
}



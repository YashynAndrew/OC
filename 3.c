#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
struct thread_arg{
	int time;
	
};

void * func(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	int i = 0;
	while(i<targ.time){
	fprintf(stderr,"Iteration %d\n",i+1);
	i++;
	sleep(1);}
}

int main(int argc,const char *argv[]){
	if(argc == 1){
		printf("Nothing here\n");
		return 0;
	}
	
	int time = atoi(argv[1]);
	int i;
	void* result;
	struct thread_arg t;
	t.time = time*2;
	pthread_t thread;
	pthread_create(&thread,NULL,&func,&t);
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
	sleep(time);
	pthread_join(thread,NULL);
	pthread_cancel(thread);
	if(!pthread_equal(pthread_self(),thread)){
		pthread_join(thread,&result);
	}
	if(result==PTHREAD_CANCELED){
		fprintf(stderr,"Canceled \n");
	}else fprintf(stderr,"NOT Canceled \n");

	return 0;
}

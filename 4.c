#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


void * func(void * arg){
	double i = 3;
	int old_cancel_state;
	int n = 1;
	double res = 1; 
	
	while(i<100000){
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&old_cancel_state);
		res+=(1/i)*pow((-1),n);
		i+=2;
		n++;
		pthread_setcancelstate(old_cancel_state,NULL);
		pthread_testcancel();
	}
	fprintf(stderr,"PI = %f \n",res*4);
	return 0;
	
}

int main(int argc,const char *argv[]){
	if(argc == 1){
		printf("Nothing here\n");
		return 0;
	}
	
	int time = atoi(argv[1]);
	int i;
	void* result;
	pthread_t thread;
	pthread_create(&thread,NULL,&func,NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
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

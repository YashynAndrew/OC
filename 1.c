#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
int arr[10]; 
struct thread_arg{
	int num;
	
};

void * prin(void * arg){
	int i = 0;
	struct thread_arg targ = *(struct thread_arg *) arg;
	while(1){
		fprintf(stderr,"Array: ");
		while(arr[i]!=0){
			fprintf(stderr,"%d ",arr[i]);
			i++;
		}
		if(arr[targ.num]!=0){
			return 0;
		}
		sleep(1);
		i = 0;
		fprintf(stderr,"\n");
	}
}

void * func(void * arg){
	srand(time(NULL));
	struct thread_arg targ = *(struct thread_arg *) arg;
	int i;
	fprintf(stderr,"Sleeping for %d\n",targ.num);
	sleep(targ.num);
	arr[targ.num] = 1+rand()%10;
	fprintf(stderr,"Random number: %d\n",arr[targ.num]);
	fprintf(stderr,"Sleeping for %d\n",arr[targ.num]);
	sleep(arr[targ.num]);
	return NULL;
}

int main(int argc,const char *argv[]){
	if(argc == 1){
		printf("Nothing here\n");
		return 0;
	}
	
	int amount = atoi(argv[1]);
	int i;
	struct thread_arg t;
	t.num = amount-1;
	pthread_attr_t attr;
	pthread_t thread1;
	pthread_attr_init(&attr);
	pthread_create(&thread1,&attr,&prin,&t);
	for(i=0;i<amount;i++){
		struct thread_arg t;
		t.num = i;
		pthread_attr_t attr;
		pthread_t thread;
		pthread_attr_init(&attr);
		pthread_create(&thread,&attr,&func,&t);
		pthread_join(thread,NULL);
	}
	
	
	
	return 0;
}

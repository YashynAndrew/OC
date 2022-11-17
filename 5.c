#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
static pthread_key_t thread_key;

void * func(void * arg){
	char thread_name[100] = "thrd";
	fprintf(stderr,"Thread %ld\n",pthread_self());
	pthread_setspecific(thread_key,thread_name);
	srand(time(NULL));
	int number = rand()%5;
	fprintf(stderr,"number %d\n",number);
	int i = 0;
	while(i<number){
		fprintf(stderr,"Thread ");
		fprintf(stderr,"%ld ",pthread_self());
		fprintf(stderr,"Iteration %d\n",i+1);
		i++;
		sleep(1);
	}
}

int main(int argc,const char *argv[]){
	srand(time(NULL));
	if(argc == 1){
		printf("Nothing here\n");
		return 0;
	}
	
	int amount = atoi(argv[1]);
	int i=0;
	for(i=0;i<amount;i++){
		pthread_t thread;
		pthread_create(&thread,NULL,&func,NULL);
	}
	pthread_t thread;
	pthread_create(&thread,NULL,&func,NULL);
	pthread_join(thread,NULL);
	
	return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include<stdlib.h>
struct thread_arg{
	char* str;
	char* name;
	int num;
};

struct thread1_arg{
	int num;
	int min;
	int max;
	int goal;
};

void * func(void * arg){
	struct thread_arg targ = *(struct thread_arg *) arg;
	int i;
	for (i=0;i<targ.num;i++){
		fprintf(stderr,"Thread %s.%s %d\n",targ.name,targ.str,i+1);
		sleep(1);
	}
	return NULL;
}

void * rnd(void * arg){
	srand(time(NULL));
	struct thread1_arg targ = *(struct thread1_arg *) arg;
	int i,n;
	for (i=0;i<targ.num;i++){
		n = targ.min + rand()%(targ.max-targ.min);
		if(n == targ.goal){
			fprintf(stderr,"Num %d is found\n",targ.goal);
			return NULL;
		}
		fprintf(stderr,"Num = %d. %d\n",n,i+1);
		sleep(1);
	}
	return NULL;
}

int main(void){
	pthread_t thread1,thread2;
	//int arg;
	struct thread_arg targ1;
	struct thread1_arg targ2;
	targ1.num = 2;
	targ1.str = "aaaa";
	targ1.name = "A";
	int result;
	result = pthread_create(&thread1,NULL,&func,&targ1);
	if(result != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	targ2.num = 5;
	targ2.goal = 10;
	targ2.min = 2;
	targ2.max = 15;
	result = pthread_create(&thread2,NULL,&rnd,&targ2);
	if(result != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	if(pthread_join(thread1,NULL) != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	if(pthread_join(thread2,NULL) != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	fprintf(stderr,"End\n");
	//while(1);
	return 0;
}

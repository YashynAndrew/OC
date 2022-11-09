#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
struct thread_arg{
	char* str;
	char* name;
	int num;
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

int main(void){
	pthread_t thread1,thread2,thread3,thread4;
	//int arg;
	struct thread_arg targ1;
	struct thread_arg targ2;
	struct thread_arg targ3;
	struct thread_arg targ4;
	targ1.num = 2;
	targ1.str = "aaaa";
	targ1.name = "A";
	int result;
	result = pthread_create(&thread1,NULL,&func,&targ1);
	targ2.num = 3;
	targ2.str = "bbbbbb";
	targ2.name = "B";
	result = pthread_create(&thread2,NULL,&func,&targ2);
	targ3.num = 3;
	targ3.str = "ccc";
	targ3.name = "C";
	result = pthread_create(&thread3,NULL,&func,&targ3);
	targ4.num = 4;
	targ4.str = "dddd";
	targ4.name = "D";
	result = pthread_create(&thread4,NULL,&func,&targ4);
	if(result != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	while(1);
	return 0;
}

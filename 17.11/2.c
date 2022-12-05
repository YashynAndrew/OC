#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


double sum;
int counter;
double x,h;
pthread_mutex_t lock;

void* doSomeThing(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;
    printf("\n Tread %d started\n", counter);
   
	
    sum += 4 - (x+h/2)*(x+h/2);
    x += h;

    printf("\n Thread %d finished\n", counter);
    printf("\n Sum =  %f \n", sum);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(int argc,char *argv[])
{
	if(argc == 1){
		printf("Write n:\n");
		return 0;
	}
	int oper=1;
	counter = 0;
	oper = atoi(argv[1]);
	h = 2/(double)oper;
	printf("\n H =  %f \n", h);
	x=0;
	pthread_t threads[oper-1];
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < oper)
    {
        err = pthread_create(&(threads[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }
    i=0;
    while(i < oper)
    {
        pthread_join(threads[i], NULL);
        i++;
 
    }
    printf("\n Result Sum =  %f \n", sum*h);

    
    pthread_mutex_destroy(&lock);

    return 0;
}

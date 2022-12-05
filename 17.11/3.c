#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>


int *x = (int*)malloc(5*sizeof(int));
int size = 5;

pthread_rwlock_t lock_rw = PTHREAD_RWLOCK_INITIALIZER;

void *reader_thread(void *arg)
{


    pthread_rwlock_t *p = (pthread_rwlock_t *)arg;
    srand(time(NULL));
    int pos = rand()%size;
    pthread_rwlock_rdlock(p);
        printf("\nRead from %d = %d",pos,x[pos]);
        pthread_rwlock_unlock(p);


 

    return NULL;
}

void *writer_thread(void *arg)
{
    pthread_rwlock_t *p = (pthread_rwlock_t *)arg;
    srand(time(NULL));
    int pos = rand()%size;
    int data = rand()%size;
    pthread_rwlock_rdlock(p);
    	x[pos] = data;
        printf("\nWritten to %dpos = %d",pos,x[pos]);
        pthread_rwlock_unlock(p);

    return NULL;
}

void* prnt(void *arg)
{
int i;
printf(" Array ");
    for(i=0;i<size;i++){
    	printf(" %d ",x[i]);
    }

    return NULL;
}

int main(int argc,char *argv[])
{	if(argc == 2){
		size = atoi(argv[1]);
		x = (int*)realloc(x,size*sizeof(int));
	}
	int i=0;
	
    pthread_t threads[9];
    while(i < 3)
    {
        if (pthread_create(&(threads[i]), NULL, writer_thread, &lock_rw) != 0)
            printf("\ncan't create thread");
        i++;
    }
    while(i < 8)
    {
        
        if (pthread_create(&(threads[i]), NULL, reader_thread, &lock_rw) != 0)
            printf("\ncan't create thread");
        i++;
    }
    pthread_create(&(threads[8]), NULL, prnt, NULL);
    
    i=0;
    while(i < 9)
    {
        pthread_join(threads[i], NULL);
        i++;
    }

    return 0;
}

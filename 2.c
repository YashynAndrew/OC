#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <errno.h>

pthread_mutex_t mutex ;
pthread_cond_t condChange;    // creating the condition variable.
int flag = 0;

void* changing(void* arg) {
while(1){
srand(time(NULL));
pthread_mutex_lock(&mutex);
        flag = rand()%10 ;
        printf ( " Flag changed... %d \n " ,  flag ) ;
pthread_mutex_unlock(&mutex) ;
pthread_cond_signal(&condChange) ;
sleep(3);
}    
}

void* checking(void* arg) {
int prev=0;
while(1){
	pthread_mutex_lock(&mutex);
	if(flag!=prev){
		printf ( " Data changed to %d \n " , flag ) ;
        	prev = flag;
        }
	pthread_mutex_unlock(&mutex);}
}

int main(int argc, char* argv[]) {
pthread_t a[2] ;
pthread_mutex_init(&mutex, NULL) ;
pthread_cond_init(&condChange, NULL) ;
    for ( int i = 0 ; i < 2 ; i++ ) {
        if (i == 1) {
            if (pthread_create(&a[i], NULL, &changing, NULL) != 0) {
perror("Failed to create thread");
            }
        } else {
            if (pthread_create(&a[i], NULL, &checking, NULL) != 0) {
perror("Failed to create thread");
            }
        }
    }


    sleep(10);
	pthread_cancel(a[1]);
	pthread_cancel(a[0]);
pthread_mutex_destroy(&mutex) ;
pthread_cond_destroy(&condChange) ;   // destroying the threads.
    return 0 ;
}

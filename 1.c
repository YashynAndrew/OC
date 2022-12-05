#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
void *consumer(void *arg);
void *producer(void *arg);
sem_t bin_sem;
#define WORK_SIZE 5
int size = 0;
char work_area[WORK_SIZE];
int main() {
	int res;
	pthread_t a_thread;
	pthread_t b_thread;
	void *thread_result;
	res = sem_init(&bin_sem, 0, 1);
	if (res != 0) {
		perror("Semaphore initialization failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, &producer, NULL);
	res = pthread_create(&b_thread, NULL, &consumer, NULL);
	if (res != 0) {
	perror("Thread creation failed");
	exit(EXIT_FAILURE);
	}
	sleep(5);
	pthread_cancel(a_thread);
	pthread_cancel(b_thread);
	
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);
}

void *consumer(void *arg) {
while(1){
	sem_wait(&bin_sem);
		if(size==0){
			printf("No items\n");
			sem_post(&bin_sem);
		}else{
			printf("Took one element, left %d items\n",size-1);
			size--;
			sem_post(&bin_sem);
		}sleep(1);
		}
	
	
	pthread_exit(NULL);
}

void *producer(void *arg) {
	while(1){
		sem_wait(&bin_sem);
		if(size==WORK_SIZE){
			printf("Max size\n");
			sem_post(&bin_sem);
		}else{
			srand(time(NULL));
			work_area[size-1] = rand()%10;
			printf("Produced %d, left %d items\n",work_area[size-1],size+1);
			size++;
			sem_post(&bin_sem);
		}
		sleep(1);
		}
	
		pthread_exit(NULL);
}

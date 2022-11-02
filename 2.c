#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<time.h>

int main(){
	pid_t pid;
	pid = fork();
	int i = 0;
	int j = 0;
	time_t start = time(NULL);
	time_t now = time(NULL);
	//printf("%ld\n",now);
	while((start-now)<3){
		if(pid==0){
			i++;
			//printf("1");
		}else if(pid>0){
			i++;
			//printf("2");
		}else {printf("Error");return 0;}
		start = time(NULL);
	}
	printf("i = %d\n",i);
	i=0;
}

#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
int main(){
	int i = 0;
	pid_t pid;
	pid_t ppid;
	pid = fork();
	i++;
	printf("Next process\n");
	pid = getpid();
	ppid = getppid();
	printf("pid = %d,\nppid = %d\n",pid,ppid);
	printf("i = %d\n",i);
	fork();
	i++;
	printf("Next process\n");
	pid = getpid();
	ppid = getppid();
	printf("pid = %d,\nppid = %d\n",pid,ppid);
	printf("i = %d\n",i);
	fork();
	i++;
	printf("Next process\n");
	pid = getpid();
	ppid = getppid();
	printf("pid = %d,\nppid = %d\n",pid,ppid);
	printf("i = %d\n",i);
	return 0;
}


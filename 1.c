#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char *argv[]){
	pid_t pid = getpid();
	pid_t opt;
	pid_t ppid = getppid();
	pid_t gid = getgid();
	pid_t pgid = getpgrp();
	pid_t euid = geteuid();
	pid_t egid = getegid();
	pid_t uid = getuid();
	if(argc == 1){
		printf("pid is : %d\nppid : %d\ngroop id : %d\npgroop id : %d\neUID : %d\neGID: %d\nuser id : %d\n", pid,ppid,gid,pgid,euid,egid,uid);
		return 0;
	}
	char *opts = "upg";
	opt = getopt(argc,argv,opts);
	switch(opt){
		case 'u': printf("user id : %d\neUID : %d\neGID: %d\n",uid,euid,egid);return 0;;
		case 'p': printf("pid is : %d\nppid : %d\npgroop id : %d\n",pid,ppid,pgid);return 0;;
		case 'g': printf("groop id : %d\npgroop id : %d\n",gid,pgid);return 0;;
		default: printf("Error");return 0;
		
	}
	
}

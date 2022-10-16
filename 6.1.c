#include<stdlib.h>
#include<stdio.h>

int main(int argc,const char *argv[]){
	if(argc!=3){
		printf("Input 'name' and 'var'");
	}
	else{
		setenv(argv[1],argv[2],0);
		printf("%s = %s",argv[1],getenv(argv[1]));
	}
	

}

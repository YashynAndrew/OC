#include<stdlib.h>
#include<stdio.h>


int main(int argc,const char *argv[]){
	int i = 0;
	if(argc == 1){
		printf("Enter command");
	}
	for (i = 1; i < argc; i++){
		if(getenv(argv[i]) == NULL){
			printf("No such command: %s\n",argv[i]);
		}else printf("%s\n",getenv(argv[i]));
		
	}
}

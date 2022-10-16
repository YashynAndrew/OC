#include<stdlib.h>
#include<stdio.h>
extern char **environ;

int main(int argc,const char *argv[]){
	int i = 0;
	if(argc == 1){
		clearenv();
		printf("Nothing here\n");
		return 0;
	}
	
	for (i = 1; i < argc; i++){
		unsetenv(argv[i]);
		
	}
	i=0;

	while(environ[i]) {
  	printf("%s\n", environ[i++]);
	}
		
	
}

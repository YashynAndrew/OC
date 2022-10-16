#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc,const char *argv[]){
	
	char *string = NULL;
	if ((string = (char *)malloc(strlen(argv[1])+strlen(argv[2])+1)) == NULL){
        	perror("Error malloc");
        	return 0;
    	}
	if(argc!=3){
		printf("Input 'name' and 'value'");
	}
	else{
		strcpy(string, argv[1]);
    		strcat(string, "=");
    		strcat(string, argv[2]);
    		putenv(string);
		printf("%s = %s",argv[1],getenv(argv[1]));
	}
	

}

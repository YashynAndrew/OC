#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("usage:\n");
		printf("opts -h\n-o file_name\n-c\n");
		return 0;
	}
	//char *opts = "hoc:";
	int opt;
	int i = 0;
	char *fileName = NULL;
	FILE *fp;
	char *opts = "ho:c";
	opt = getopt(argc,argv,opts);
	switch(opt){
		case 'h':
			printf("usage:\n");
			printf("opts -h\n-o file_name\n-c\n");
			if(argc>2){
				i = 2;
				while(i<argc){
					fileName = argv[i];
					strcat(fileName,".txt");
					fp  = fopen (fileName, "r");
					printf("%s file was written\n",fileName);
					i++;
				}
			}
			break;
		case 'o':
			fileName = optarg;
			
			if ((fileName = (char *)malloc(strlen(optarg)+10)) == NULL){
        			perror("Error malloc");
        			return 0;
    			}
    			strcpy(fileName,optarg);
    			strcat(fileName,".txt");
			fp  = fopen (fileName, "w");
			printf("%s file was created\n",fileName);
			if(argc>3){
				i = 3;
				while(i<argc){
					fileName = argv[i];
					strcat(fileName,".txt");
					fp  = fopen (fileName, "r");
					printf("%s file was written\n",fileName);
					i++;
				}
			}
			break;
		case 'c':
			printf("Special mode\n");
			if(argc>2){
				i = 2;
				while(i<argc){
					fileName = argv[i];
					strcat(fileName,".txt");
					fp  = fopen (fileName, "r");
					printf("%s file was written\n",fileName);
					i++;
					
				}
				
			}
			break;
		default: 
			printf("Wrong option\n");
			break;
			
	
	}
	
		

}



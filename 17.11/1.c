#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int data = 0;
int operations = 1;

void * func_inc(void * arg){
	int i;
	for(i = 0; i< operations;i++){
		data++;
		fprintf(stderr,"Data increased %d\n",data);
	}
	
}

void * func_dec(void * arg){
int i;
	for(i = 0; i< operations;i++){
		data--;
		fprintf(stderr,"Data decreased %d\n",data);
	}
}

int main(int argc,char *argv[]){
	if(argc == 1){
		printf("usage:\n");
		printf("opts '-p' amount of pairs\n-o amount of operations\n");
		return 0;
	}
	int amount = 1;//vvod
	int opt,i;
	char *opts = "p:o:";
	opt = getopt(argc,argv,opts);
	while(opt!=-1){
	switch(opt){
		case 'p':
			printf("amout of pairs:\n");
			printf("%s\n",optarg);
			amount = atoi(optarg);
			opt = getopt(argc,argv,opts);
			break;
		case 'o':
			printf("amout of operations:\n");
			printf("%s\n",optarg);
			operations = atoi(optarg);
			opt = getopt(argc,argv,opts);
			break;
		default: 
			printf("Wrong option\n");
			opt = getopt(argc,argv,opts);
			break;
			
	
	}}
	
	
	pthread_t threads[amount*2];
	int j;
	for(i = 0,j=0; i < amount; i++){
		pthread_create(&threads[j],NULL,&func_inc,NULL);
		pthread_create(&threads[j+1],NULL,&func_dec,NULL);
		j+=2;
	}
	for(i = 0; i < amount*2; i++){
		pthread_join(threads[i],NULL);
	}
	//sleep(time);
	printf("Data = %d\n",data);
	return 0;
}

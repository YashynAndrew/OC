#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include<stdlib.h>
void * prime(void * args){
	int n=*(int *)args;
	int num=2,count,i; 
	int k = 0;
	fprintf(stderr,"The first %d prime numbers:",n);
   	while(k<n){
      		count = 0;
      		for(i=2;i<=num/2;i++){
        		if(num%i==0){
        		count++;
        		break;
        		}
   		}
   		if(count==0 && num!= 1){printf("%d ",num);k++;}
   		num++;
   		
      			
   	}
   	return 0;
}

long fact(int n){
	if(n==0){
		return 1;
	}
	return fact(n-1)*n;
}

unsigned long int catalan(unsigned int n)
{
    if (n <= 1)
        return 1;
 
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);
 
    return res;
}

void * catal(void * args){
	pthread_t thread1;
	pthread_join(thread1,NULL);
	int n=*(int *)args;
	int i;
	fprintf(stderr,"The first %d Catalan numbers:",n);
	for(i = 0;i<n;i++){
		fprintf(stderr,"%ld ",catalan(i));
	}
}

int main(){
	int a = 7;
	pthread_t thread1,thread2;
	int result;
	result = pthread_create(&thread1,NULL,&prime,&a);
	if(result != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	
	result = pthread_create(&thread2,NULL,&catal,&a);
	if(result != 0){
		fprintf(stderr,"Error\n");
		return 1;
	}
	pthread_join(thread2,NULL);
	int i;
	return 0;
}

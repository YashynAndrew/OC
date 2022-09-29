
#include <stdio.h>
#include <math.h>
#include <time.h>


int main(){
	srand(time(NULL));
	int i = 0;
	int a[11]; 
	bool flag = false;
	int sum = 0;
	int sumMod = 0;
	int num = 0;
	double avg = 0;
	
	for(i=0; i<=10; i++){
		a[i] = rand()%100 * pow((-1),rand()%2);
		printf(" %d ",a[i]);
		sum+=a[i];
	}
	printf("\n");
	avg = sum/11;
	
	for(i=0; i<=10; i++){
		if(a[i]>avg){
			num++;
		}
		
		if(flag == true){
			sumMod+=abs(a[i]);
		}
		
		if(flag == false && a[i] < 0){
			flag = true;
		}
	}
	
	printf("Srednee: %f\nBolshe srednego: %d\nSumma modulei: %d\n",avg,num,sumMod);
	
	

	
	


}

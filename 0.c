#include <stdio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>
int size_a = 10;
int min_mass = 1000;//bolshe max vozmozhnogo
int min_rast = 142;//bolshe max vozmozhnogo
int min_ri;
int min_i;
int a[10][3];

int main(){
	int j = 0;
	int i = 0;
	srand(time(NULL));
	for(i = 0;i<10;i++){
		for(j = 0; j<3;j++){
			a[i][j] = rand()%100;
		}
		printf("\ni.%d mass: %d,x = %d,y = %d",i,a[i][0],a[i][1],a[i][2]);
		
	}
	
	while(size_a!=1){
		for(i = 0;i<10;i++){
			if(min_mass>a[i][0] && a[i][0]!=-1){
			min_mass = a[i][0];
			min_i = i;
			}
		}
		for(i = 0;i<10;i++){
			if(i!=min_i && a[i][0]!=-1){
				int rast = sqrt(pow(a[i][1]-a[min_i][1],2)+pow(a[i][2]-a[min_i][2],2));
				if(min_rast>rast){
					min_rast = rast;
					min_ri = i;
				}
			}
			
		}
		printf("\nmin = %d\n",min_mass);
		//printf("\nmin rast = %d\n",min_rast);
		a[min_ri][0]+=a[min_i][0];
		a[min_i][0] = -1;
		a[min_i][1] = -1;
		a[min_i][2] = -1;
		printf("Tochka %d ischezla i peredala masu tochke %d",min_i,min_ri);
		min_mass = 1000;
		min_rast = 142;
		size_a--;
		for(i = 0;i<10;i++){
	
		printf("\ni.%d mass: %d,x = %d,y = %d",i,a[i][0],a[i][1],a[i][2]);
		
		}
		
	}
	
	
	
	printf("\nKonec");
	for(i = 0;i<10;i++){
	
		printf("\ni.%d mass: %d,x = %d,y = %d",i,a[i][0],a[i][1],a[i][2]);
		
	}

	
	

}

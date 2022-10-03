#include <stdio.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

void add(int item);
int remove(int index);
void insert(int index,int item);
int size();
int set(int index,int item);
int get(int index);
int *a = (int*)malloc(10*sizeof(int));
int i;
int size_a = 10;


int main(){
	srand(time(NULL));
	int i = 0;
	for(i = 0; i<size_a;i++){
		a[i] = rand()%100 * pow((-1),rand()%2);
		printf(" %d ",a[i]);
	}
	printf("\nAfter add 100\n");
	add(100);
	for(i = 0; i<size_a;i++){
		printf(" %d ",a[i]);
	}
	remove(5);
	printf("\nAfter remove 5th\n");
	for(i = 0; i<size_a;i++){
		printf(" %d ",a[i]);
	}
	insert(3,77);
	printf("\nAfter insert 3rd 77\n");
	for(i = 0; i<size_a;i++){
		printf(" %d ",a[i]);
	}
	printf("\nSize: %d",size());
	printf("\nAfter set 5th 876\n");
	set(5,876);
	for(i = 0; i<size_a;i++){
		printf(" %d ",a[i]);
	}
	
	printf("\nGet 6: %d",get(6));	
	free(a);
	//printf(" %d ",a[size-1]); 
}

void add(int item){
	size_a++;
	a = (int*)realloc(a,sizeof(int)*size_a);
	a[size_a-1] = item;	
}

int remove(int index){
	int temp = a[index];
	for(int i = index+1;i<size_a;i++){
		a[i-1] = a[i];	
	}
	a = (int*)realloc(a,sizeof(int)*(size_a-1));
	size_a--;
	return	temp;
}

void insert(int index,int item){
	a = (int*)realloc(a,sizeof(int)*(size_a+1));
	for(int i = size_a-1;i>=index;i--){
		a[i+1] = a[i];
	}
	a[index] = item;
	size_a++;
}

int size(){
	return size_a;
}

int set(int index, int item){
	int temp = a[index]; 
	a[index] = item;
	return temp;
}

int get(int index){
	return a[index];

}





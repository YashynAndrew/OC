#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(int argc,const char *argv[]){
	if(argc!=4){
		printf("Input 'a', 'b' and 'c'\n");
	}else{
		long des = 0;
		long a;
		long b;
		long c;
		a = atol(argv[1]);
		b = atol(argv[2]);
		c = atol(argv[3]);
		printf("%ldx^2 + (%ld)x + (%ld)\n",a,b,c);
		des = b*b - 4*a*c;
		if(des<0){
			printf("No anwers\n");
			return 0;
		}
		if(des == 0){
			long x = (-b)/(2*a);
			printf("x = %ld\n",x);
			return 0;
		}
		long x1,x2;
		x1 = ((-b)-sqrt(des))/(2*a);
		x2 = ((-b)+sqrt(des))/(2*a);
		printf("x1 = %ld;  x2 = %ld\n ",x1,x2);
	}
	
}

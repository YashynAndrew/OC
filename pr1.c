#include <stdio.h>
#include <math.h>

int main(){
	double x;
	printf("Input x \n");
	scanf("%lf",&x);
	printf("f(x) = exp(-|x|)sin(x) = %lf\n",exp(-abs(x)) * sin(x));
	printf("g(x) = exp(-|x|)cos(x) = %lf\n",exp(-abs(x)) * cos(x));
	return 0;
	
	}
	


#include <stdio.h>
#include <math.h>

void f(double x){
	double res = exp(-fabs(x)) * sin(x);
	printf("%lf\n",res);
}


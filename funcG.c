#include <stdio.h>
#include <math.h>

void g(double x){
	double res = exp(-fabs(x)) * cos(x);
	printf("%lf\n",res);
}


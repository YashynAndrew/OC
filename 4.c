#include<stdlib.h>
#include<stdio.h>
extern char **environ;
int main(){
	int i = 0;
	while(environ[i]) {
  	printf("%s\n", environ[i++]);
	}
}

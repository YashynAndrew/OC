#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int kaz(int money){
	srand(time(NULL));
	int a = rand()%10;
	int b = rand()%10;
	int c = rand()%10;
	

    	char cmd[1024];
    	sprintf(cmd, "xmessage -center \"%d %d %d\n\"",a,b,c);
    	system(cmd);
    
   	if(((a == b) && (b == c) && (c == 0)) ||((a == b) && (b == c) && (c == 1)) ||((a == b) && (b == c) && (c == 2)) ||((a == b) && (b == c) && (c == 3)) ||((a == b) && (b == c) && (c == 4))){
   		return 3;
   	}
   	
   	if((a == b) && (b == c) && (c == 6)){
   		return 6;
   	}
   	
   	if((a == b) && (b == c) && (c == 7)){
   		return 7;
   	}
   	
   	if((a == b) && (b == c) && (c == 5)){
   		return 5;
   	}
   	
   	if((a == 5 && b == c) || (b == 5 && a == c) || (c == 5 && b == a)){
   		return 4;
   	}
   	
   	if((a == 7 && b == c) || (b == 7 && a == c) || (c == 7 && b == a)){
   		return 4;
   	}
   	
   	if((a == 5 && b == 5 && c != 5) || (a == 5 && c == 5 && b != 5) || (c == 5 && b == 5 && a !=5)){
   		return 3;
   	}
   	
   	if((a == 7 && b == 7 && c != 7) || (a == 7 && c == 7 && b != 7) || (c == 7 && b == 7 && a !=7)){
   		return 3;
   	}
   	
   	 
    	return 1;
}


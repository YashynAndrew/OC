#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int kaz(int money);
int main(){
	int money = 5000;
	
    char cmd[1024];
    int res = 0;
    while(money>=500 && res != 7){
    	res = kaz(money);
    	if(res == 1){
    		money -= 500;
    	}
    	
    	if(res == 3){
    		money += 1500;
    	}
    	
    	if(res == 4){
    		money += 500;
    	}
    	
    	if(res == 5){
    		money += 1000;
    	}
    	
    	if(res == 6){
    		money -= 1000;
    	}
    	
    	if(res == 7){
    		sprintf(cmd, "xmessage -center \"%s\"","You won!!!");
    		system(cmd);
    		return 0;
    	}
    	
    	if(money < 500){
    		sprintf(cmd, "xmessage -center \"You have just lost.\n Balance: %d\"",money);
    		system(cmd);
    		return 0;
    	}
    	
    	sprintf(cmd, "xmessage -center \"Balance: %d\"",money);
   	system(cmd);
   	
   
    	
    	

    }
    
    return 0;
}



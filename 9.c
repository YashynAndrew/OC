#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>
#include <unistd.h>

int main(void) {
	char hostname[1024];
	
    	gethostname(hostname, 1024);
    	printf("Hostname:");
    	puts(hostname);

   	struct utsname buffer;

   	if (uname(&buffer) < 0) {
      	perror("uname");
      	return 0;
   	}

   	printf("system name = %s\n", buffer.sysname);
   	printf("node name = %s\n", buffer.nodename);
   	printf("release = %s\n", buffer.release);
   	printf("version = %s\n", buffer.version);
   	printf("machine = %s\n", buffer.machine);
   	printf("hostId = %ld\n",gethostid());

}

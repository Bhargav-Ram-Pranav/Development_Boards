#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
 
#define PIN_ON _IOW('c','a',int32_t*)
 
int main()
{
        int fd;
        int32_t value, number;
        
 
        printf("\nOpening Driver\n");
        fd = open("/dev/GPIO_DEV", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }
 
        printf("Enter the Value to send\n");
	while(1)
	{
		scanf("%d",&number);
		__fpurge(stdin);
		printf("Writing Value to Driver\n");
		ioctl(fd, PIN_ON, (int32_t*) &number); 
	} 

	printf("Closing Driver\n");
	close(fd);
}

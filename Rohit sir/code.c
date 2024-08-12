#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>


int main()
{
	int fd1 = open("foo.txt" , O_RDONLY);

	if( fd1 == -1) {
	   
		perror("Here's an error :) ");

		exit(1);
	}

	printf("Opened the fd = %d \n" , fd1);

       // USING THE CLOSE SYSTEM CALL 
       
	if( close(fd1) == -1 ){
	
		perror("here's an error :) ");
	}

	printf("Successfully closed the fd. \n");

}

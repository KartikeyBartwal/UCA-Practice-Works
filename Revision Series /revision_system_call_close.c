#include <fcntl.h> // FOR open()
#include <stdio.h>
#include <unistd.h> // FOR read() and close()
#include <stdlib.h> 


int main() {

  int fd1 = open("foo.txt" , O_RDONLY);

  if( fd1 == -1 ){

    perror("Couldn't open or create the file");
  
    exit(1);
  
  }

  // ATTEMPT TO CLOSE THE FILE DESCRIPTOR

  int close_fd1 = close( fd1 );

  if( close_fd1 == -1) {

    perror("Couldn't close file");

    exit( 1 );
    
  }

  else{
  
    printf("Closed the file descriptor \n");
    
  }

 
}

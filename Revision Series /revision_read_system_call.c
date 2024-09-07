#include <fcntl.h> // for open()
#include <stdio.h>
#include <unistd.h> // for read() and close()
#include <stdlib.h>
#include <string.h>

int main() {

  int fd, sz;

  char *c = ( char * ) calloc( 100 , sizeof( char));

  if( c == NULL) {

    perror(" Memory allocation failed ");

    exit( 1 );
    
  }

  fd = open( "foo.txt" , O_RDONLY | O_CREAT);

  if( fd < 0 ) {

      perror( "Error opening the file");

      exit( 1 );
  }

  sz = read( fd , c , 10);

  if( sz == -1 ) {

    perror("Error reading file");

    close( fd );

    exit( 1 );
  }
c[sz] = '\0';
    printf("Called read(%d, c, 10). Returned that %d bytes were read.\n", fd, sz);
  printf("Those bytes are as follows: %s\n", c);

  return 0;
}




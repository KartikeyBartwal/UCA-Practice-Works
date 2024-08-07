#include <unistd.h>
#include <stdio.h>


int main(){

  if(fork() && (!fork())){

          if(fork() || fork()){

                  fork();
          }

  }

  printf("2 \n");

          return 0;
}

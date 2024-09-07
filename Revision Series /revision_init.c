#include <stdio.h>

int main() {

  unsigned int a = 128;

  int *b = &a;
  char *c = &a;

  printf(" %u \n" , *b);
  prinf("%u \n" , *c);
  
}

// %u -> signed int
// This will not run since %u is for signed int and c is a character pointer

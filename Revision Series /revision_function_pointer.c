#include <stdio.h>

int add( int a, int b ) {
    
  return a + b;  
};

int subtract( int a, int b ) {
    
    return a - b;
    
}

int multiplication( int a, int b ) {
  
  return a * b;  
    
};


int division( int a, int b ) {
    
    return ( int ) a / b;
}


void performOperation( int (*operation)( int , int ), int a , int b) {
    
    int result = operation( a, b );
    
    printf( "Result: %d \n" , result);
};

int main()
{
    int a = 10, b = 5;
    
    performOperation( add , a , b );
    
    performOperation( subtract , a , b );
    
    performOperation( multiplication , a , b );
    
    performOperation( division , a , b );

    return 0;
}

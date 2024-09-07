/*
https://www.youtube.com/watch?v=z-MHVnhpf9w
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  sign_t -> Unsigned integer

typedef struct {
  void **elements;
  size_t size;
  size_t capacity;
} List;

void initList( List *list, size_t initialCapacity) {

  list->elements = ( void **) malloc( initialCapacity * sizeof( void * ) ) ;
  list->size = 0;
  list->capacity = initialCapacity;
  
}

void addElement( list *list, void *element) {

  if( list->size == list->capacity) {

    list->capacity *= 2;
    list->elements = ( void **) realloc( list->elements , list->capacity * sizeof( void *));
  }
  list->elements[ list->size++] = element;
  
}

void printList( list *list, void (*printFunc) ( void *)) {

  for( size_t i = 0; i < list->size; i++ ) {

      printFunc( list->elements[ i ] );
  }

  printf("\n");
}

void sortList( List *list, int (*compareFunc) ( const void *, const void *)) {
  for( size_t i = 0; i < list->size - 1;i++ ) {

      for( size_t j = 0; j < list->size - i - 1; j++ ) {

         if( CompareFunc( list->elements[ j ] , list->elements[ j + 1] > 0 ) {

             void *temp = list->elements[ j ];
             list->elements[ j ] = list->elements[ j + 1];
             list->elements[ j + 1 ] = temp;
         }
      }
  }
  
}


int compareInt( const void *a, const void *b) {

  int intA = *( int * )a;
  int intB = *( int * )b;

  return ( intA > intB ) - (intA < intB);
}

int compareString( const void *a, const void *b) {

   char *strA = *( char **)a;
   char *strB = *( char **)b;

  return strcmp( strA, strB);
}

void printInt( void *elmeent) {

   printf("%d" , *( int *) element);
}

void printString( void *element) {

  printf("%s" , *( char **) element);
}


int main() {

  List intList;
  List stringList;

  initList( &intList , 5);
  initList( &stringList , 5);

  int a = 
}









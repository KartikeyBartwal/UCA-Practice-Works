#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define BITS_PER_CHAR 8
#define BITS_PER_CHUNK 6

char* get_input_string() {
    
    char* input = malloc( MAX_INPUT_LENGTH * sizeof(char) );
    
    if ( input == NULL ) {
        
        fprintf( stderr , "Memory Allocation Failed \n" );
        
        exit( 1 );
    }
    
    printf(" Enter a string: ");
    
    if( fgets( input , MAX_INPUT_LENGTH , stdin) == NULL ) {
        
        fprintf( stderr , "Error Reading Input \n");
        
        free( input );
        
        exit( 1 );
    }

    // Remove trailing newline if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    
    return input;
}


char** create_bit_chunks( const char* binary, int* chunk_count ) {
    
    size_t binary_length = strlen( binary );
    
    *chunk_count = ( binary_length + BITS_PER_CHUNK - 1) / BITS_PER_CHUNK;
    
    char** chunks = malloc( *chunk_count * sizeof( char* ));
    
    if( chunks == NULL ) {
        
        fprintf( stderr , "Memory Allocation Failed \n");
        
        exit( 1 );
    }
    
    for(int i = 0; i < *chunk_count; i++ ) {
        
        chunks[i] = malloc( (BITS_PER_CHUNK + 1) * sizeof(char) );
        
        if( chunks[i] == NULL ) {
            
            fprintf( stderr , "Memory allocation failed\n");
            
            exit( 1 );
        }
        
        // COPY 6 BITS FOR LESS FOR THE LAST CHUNK INTO THE CHUNK 
        
        for( int j = 0; j < BITS_PER_CHUNK; j++ ) {
            
            int index = i * BITS_PER_CHUNK + j;
            
            if( index < binary_length) {
                
                chunks[i][j] = binary[ index ];
            }
            else{
                
                chunks[i][j] = '0'; // PAD WITH '0' IF WE RUN OUT OF BITS 
            }
        }
        
        chunks[i][BITS_PER_CHUNK] = '\0'; // NULL TERMINATOR FOR THE CHUNKS 
    }
    
    return chunks;
} 



char *get_binary_representation( const char* input ) {
    
    size_t input_length = strlen( input );
    
    char* binary = malloc( (input_length * BITS_PER_CHAR + 1) * sizeof( char ));
    
    if( binary == NULL ) {
        
        fprintf( stderr , "Memory Allocation Failed \n" );
        
        exit( 1 );
    }
    
    binary[0] = '\0'; // INITIALIZE AN EMPTY STRING 
    
    for( size_t i = 0; i < input_length; i++ ) {
        
        char byte = input[i];
        
        for( int j = BITS_PER_CHAR - 1; j >= 0; j-- ) {
            
            char bit = ( byte & ( 1 << j )) ? '1' : '0';
            
            strncat( binary , &bit , 1);
        }
    }
    
    return binary;
};


char map_chunk_to_char( const char* chunk ) {
    
    // CONVERT BINARY STRING TO INTEGER 
    
    int value = 0;
    
    for( int i = 0; i < BITS_PER_CHUNK; i++ ) {
        
        value = ( value << 1 ) + ( chunk[i] - '0' );
    }
    
    // MAP TO BASE64 CHARACTER 
    
    if( value < 26 ) {
        
        return 'A' + value;
    }
    else if ( value < 52 ) {
        
        return 'a' + ( value - 26 );
    }
    
    else if( value < 62) {
        
        return '0' + ( value - 52 );
    }
    
    else if( value == 62) {
        
        return '+';
    }
    else{ 
        
        return '/';   
    }
    
}
char* encode_chunks( char** chunks , int chunk_count ) {
    
    char* encoded = malloc( ( chunk_count + 1 ) * sizeof( char ) );
    
    if( encoded == NULL ) {
        
        fprintf( stderr , "Memory allocation failed \n " );
        
        exit( 1 );
    }
    
    for( int i = 0; i < chunk_count; i++ ) {
        
        encoded[i] = map_chunk_to_char( chunks[i] );
    }
    
    encoded[ chunk_count ] = '\0';
    
    
    return encoded;
}

int main()
{
    // 1) Take string as input
    
    char* input_string = get_input_string();
    
    printf(" You entered: %s \n" , input_string);
    
    
    
   // 2) Get the entire string representation of all the characters in the strings. The characters are in the form of 8 bits. 
    
    char* binary_representation = get_binary_representation( input_string );
    
    printf(" Binary representation: %s \n " , binary_representation);
    


   // 3) Do a static sliding window which takes 6 bits at a time and passes the 6 bit representation to the map.
    
    int chunk_count;
    
    char** bit_chunks = create_bit_chunks( binary_representation , &chunk_count );
    
    printf("6-bit chunks: \n");
    
    for( int i = 0; i < chunk_count; i++ ) {
        
        printf("%s \n" , bit_chunks[i]);
    }
    
    
   // 4) The map has the base64 representations for the 6 bit numbers. When given a 6 bit number it returns the associated character for it 
    
    
    char* encoded_string = encode_chunks( bit_chunks , chunk_count );
    
    printf(" Encoded string: %s \n" , encoded_string);
    
    
    
    // FREE ALLOCATED MEMORY 
    
    free( input_string );
    
    free( binary_representation );
    
    for( int i = 0; i < chunk_count; i++ ) {
        
        free( bit_chunks[i] );
    }
    
    free( bit_chunks );

    return 0;
}


/*

1) Take string as input

2) Get the entire string representation of all the characters in the strings. The characters are in the form of 8 bits. 

3) Do a static sliding window which takes 6 bits at a time and passes the 6 bit representation to the map.

4) The map has the base64 representations for the 6 bit numbers. When given a 6 bit number it returns the associated character for it 

5) Append that character to the output string 


6) This entire thing happens in the encoder function. The encoder function takes the string as the input.

*/

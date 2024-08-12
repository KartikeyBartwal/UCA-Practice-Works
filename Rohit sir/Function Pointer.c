#include <stdio.h>

// DEFINE A FUNCTION THAT TAKES TWO INTEGERS AND RETURNS THEIR DIFFERENCE
int Subtract(int a, int b) {
    return a - b;
}

// DEFINE A FUNCTION THAT TAKES TWO INTEGERS AND RETURNS THEIR QUOTIENT
int Divide(int a, int b) {
    // CHECK IF THE DENOMINATOR IS ZERO TO AVOID DIVISION BY ZERO
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0; // RETURNING ZERO AS A FALLBACK VALUE
    }
}

// DEFINE A FUNCTION THAT TAKES TWO INTEGERS AND RETURNS THEIR SUM
int Add(int a, int b) {
    return a + b;
}

// DEFINE A FUNCTION THAT TAKES TWO INTEGERS AND RETURNS THEIR PRODUCT
int Multiply(int a, int b) {
    return a * b;
}

int main() {
    // DECLARE A FUNCTION POINTER
    int (*operation)(int, int);

    // ASSIGN FUNCTION POINTER TO THE ADD FUNCTION
    operation = &Add;
    printf("Addition: %d\n", operation(5, 3)); // OUTPUT: 8

    // ASSIGN FUNCTION POINTER TO THE SUBTRACT FUNCTION
    operation = &Subtract;
    printf("Subtraction: %d\n", operation(5, 3)); // OUTPUT: 2

    // ASSIGN FUNCTION POINTER TO THE MULTIPLY FUNCTION
    operation = &Multiply;
    printf("Multiplication: %d\n", operation(5, 3)); // OUTPUT: 15

    // ASSIGN FUNCTION POINTER TO THE DIVIDE FUNCTION
    operation = &Divide;
    printf("Division: %d\n", operation(6, 3)); // OUTPUT: 2
    printf("Division: %d\n", operation(6, 0)); // OUTPUT: Error: Division by zero!

    return 0;
}

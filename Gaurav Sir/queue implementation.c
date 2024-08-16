
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

// STRUCTURE TO REPRESENT A NODE IN THE QUEUE
struct Node {
    int value;
    struct Node* next;
};

// TYPEDEFINITION FOR EASE OF USE
typedef struct Node Node;

// HEAD AND TAIL POINTERS TO KEEP TRACK OF THE QUEUE
Node* head = NULL;
Node* tail = NULL;

// VARIABLE TO TRACK THE SIZE OF THE QUEUE
int count = 0;

// FUNCTION TO CHECK IF THE QUEUE IS EMPTY
bool isEmpty() {
    return count == 0;
}

// FUNCTION TO ADD AN ELEMENT TO THE END OF THE QUEUE
void enqueue(int value) {
    Node* previousTail = tail;
    tail = (Node*) malloc(sizeof(Node));
    tail->value = value;
    tail->next = NULL;

    if(isEmpty()) head = tail;
    else previousTail->next = tail;

    count++;
}

// FUNCTION TO REMOVE AND RETURN THE ELEMENT AT THE FRONT OF THE QUEUE
int dequeue() {
    if(isEmpty()) return INT_MIN;
    int value = head->value;
    Node* temp = head;
    head = head->next;
    
    if(isEmpty()) tail = NULL;
    
    count--;
    free(temp);
    return value;
}

// FUNCTION TO GET THE NUMBER OF ELEMENTS IN THE QUEUE
int size() {
    return count;
}

// FUNCTION TO TEST THE QUEUE IMPLEMENTATION
void testQueue() {
    enqueue(3);
    enqueue(10);
    enqueue(20);

    assert(!isEmpty());
    assert(size() == 3);
    assert(dequeue() == 3);
    assert(size() == 2);
    assert(dequeue() == 10);
    assert(size() == 1);
    assert(dequeue() == 20);
    assert(size() == 0);
    assert(isEmpty());
}

int main() {
    testQueue();
    printf("All tests passed!\n");
    return 0;
}

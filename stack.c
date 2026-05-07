#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5 // Small size so we can easily test overflow 📦

// 1. Define the Stack structure
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// 2. Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1; // -1 means the stack is empty 🪹
}

// 3. Check if the stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1; 
}

// 4. Check if the stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// 5. Push a new item onto the stack 📥
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->top++; // Move the top pointer up
        s->items[s->top] = value; // Insert the value
        printf("Pushed %d onto the stack.\n", value);
    }
}

// 6. Pop the top item off the stack 📤
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1; // Return an error value
    } else {
        int poppedValue = s->items[s->top]; // Get the top value
        s->top--; // Move the top pointer down
        return poppedValue;
    }
}

int main() {
    struct Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Popped value: %d\n", pop(&myStack)); // Should print 30
    printf("Popped value: %d\n", pop(&myStack)); // Should print 20

    return 0;
}
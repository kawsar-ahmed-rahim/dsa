// Array Based Stack in C
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Display stack
void display() {
    int i;

    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    return 0;
}
// Delete a Node from Linked Stack in C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation
void push(int value) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation (Delete)
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    if (top->next != NULL) {
        top = top->next;
    } else {
        top = NULL;
    }

    printf("%d deleted from stack\n", temp->data);
    free(temp);
}

// Display stack
void display() {
    struct node *ptr = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are:\n");

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    pop();
    pop();

    display();

    return 0;
}
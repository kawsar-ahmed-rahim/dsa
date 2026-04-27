// Add a Node to Linked Stack in C
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation (Add Node)
void push(int value) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (top == NULL) {
        top = newNode;
    } else {
        newNode->next = top;
        top = newNode;
    }

    printf("%d added to stack\n", value);
}

// Display stack
void display() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    return 0;
}
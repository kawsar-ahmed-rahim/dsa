// Linked Stack Creation in C
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;   // top pointer

// Push function (insert element)
void push(int item) {
    struct node *nptr;

    nptr = (struct node*)malloc(sizeof(struct node));

    if (nptr == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    nptr->data = item;
    nptr->next = NULL;

    // Make link
    if (top == NULL) {
        top = nptr;
    } else {
        nptr->next = top;
        top = nptr;
    }
}

// Display stack
void display() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Linked Stack:\n");
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
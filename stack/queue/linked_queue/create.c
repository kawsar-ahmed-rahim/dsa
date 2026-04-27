#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *frontptr = NULL;
struct node *rearptr = NULL;

// Enqueue (Insert)
void enqueue(int item) {

    struct node *nptr;
    nptr = (struct node*) malloc(sizeof(struct node));

    if (nptr == NULL) {
        printf("Overflow\n");
        return;
    }

    nptr->data = item;
    nptr->next = NULL;

    if (rearptr == NULL) {   // empty queue
        frontptr = rearptr = nptr;
    } else {
        rearptr->next = nptr;
        rearptr = nptr;
    }

    printf("%d inserted into queue\n", item);
}

// Dequeue (Delete)
void dequeue() {

    struct node *temp;

    if (frontptr == NULL) {
        printf("Underflow\n");
        return;
    }

    temp = frontptr;
    printf("%d deleted from queue\n", temp->data);

    frontptr = frontptr->next;

    if (frontptr == NULL) {   // queue becomes empty
        rearptr = NULL;
    }

    free(temp);
}

// Display queue
void display() {

    struct node *temp;

    if (frontptr == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = frontptr;
    printf("Queue elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);

    display();

    return 0;
}
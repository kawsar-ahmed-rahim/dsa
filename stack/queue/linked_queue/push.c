#include <stdio.h>
#include <stdlib.h>

// Step 1: Declare node and pointers
struct node {
    int data;
    struct node *next;
};

struct node *frontptr = NULL;
struct node *rearptr = NULL;

// Enqueue operation
void enqueue(int item) {

    // Step 3: Create a new node
    struct node *nptr;
    nptr = (struct node*) malloc(sizeof(struct node));

    if (nptr == NULL) {
        printf("Overflow\n");
        return;
    }

    nptr->data = item;
    nptr->next = NULL;

    // Step 4: Make link among pointers
    if (rearptr == NULL) {
        frontptr = rearptr = nptr;
    } else {
        rearptr->next = nptr;
        rearptr = nptr;
    }

    printf("%d inserted\n", item);
}

// Display queue
void display() {
    struct node *temp = frontptr;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

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

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Step 1: Declare node and pointers
struct node {
    int data;
    struct node *next;
};

struct node *frontptr = NULL;
struct node *rearptr = NULL;

// Dequeue operation
void dequeue() {

    struct node *nptr;

    // Step 2: Check if queue is empty
    if (frontptr == NULL) {
        printf("Underflow\n");
        return;
    }

    // Step 3: Take node from front
    nptr = frontptr;
    printf("%d deleted\n", nptr->data);

    // Step 4: Move front pointer
    frontptr = frontptr->next;

    // Step 5: If queue becomes empty
    if (frontptr == NULL) {
        rearptr = NULL;
    }

    // Step 6: Free memory
    free(nptr);
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

    // Creating queue manually using enqueue logic
    struct node *n1 = (struct node*) malloc(sizeof(struct node));
    struct node *n2 = (struct node*) malloc(sizeof(struct node));
    struct node *n3 = (struct node*) malloc(sizeof(struct node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;

    frontptr = n1;
    rearptr = n3;

    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
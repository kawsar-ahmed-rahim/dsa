// Array Based Queue: Delete an Element (Dequeue)

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = 0;

// Insert operation
void enqueue(int value) {
    if (rear == MAX) {
        printf("Queue Overflow\n");
    } else {
        queue[rear] = value;
        rear++;
        printf("%d inserted into queue\n", value);
    }
}

// Delete operation
void dequeue() {
    int item;

    if (front == rear) {
        printf("Queue is empty\n");
    } 
    else if (front == rear - 1) {
        item = queue[front];
        front = rear = 0;
        printf("%d deleted from queue\n", item);
    } 
    else {
        item = queue[front];
        front = front + 1;
        printf("%d deleted from queue\n", item);
    }
}

// Display queue
void display() {
    if (front == rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
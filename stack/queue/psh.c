// Array Based Queue: Add an Element (Enqueue)

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = 0;

// Insert operation
void enqueue(int item) {
    if (rear == 0) {
        front = rear = 1;
        queue[rear] = item;
        printf("%d inserted into queue\n", item);
    }
    else if (rear < MAX) {
        rear = rear + 1;
        queue[rear] = item;
        printf("%d inserted into queue\n", item);
    }
    else {
        printf("Queue Overflow\n");
    }
}

// Display queue
void display() {
    if (rear == 0) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
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

    return 0;
}
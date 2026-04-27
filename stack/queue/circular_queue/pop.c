#include <stdio.h>
#define MAX 5

int queue[MAX + 1];
int front = 0, rear = 0;

// Insert operation (Enqueue)
void enqueue(int item) {

    if (rear == 0) {   // queue initially empty
        front = rear = 1;
        queue[rear] = item;
        printf("%d inserted into queue\n", item);
    }

    else if (rear == MAX && front > 1) {  
        rear = 1;
        queue[rear] = item;
        printf("%d inserted into queue\n", item);
    }

    else if (rear >= 1 && rear < front - 1) {  
        rear = rear + 1;
        queue[rear] = item;
        printf("%d inserted into queue\n", item);
    }

    else if ((front == 1 && rear == MAX) || (front == rear + 1)) {
        printf("Queue Overflow\n");
    }
}

// Delete operation (Dequeue)
void dequeue() {

    int item;

    if (rear == 0) {   // queue empty
        printf("Queue Underflow\n");
        return;
    }

    item = queue[front];
    printf("%d deleted from queue\n", item);

    if (front == rear) {   // only one element
        front = rear = 0;
    }

    else if (front == MAX) {   // wrap around
        front = 1;
    }

    else {   // normal increment
        front = front + 1;
    }
}

// Display queue
void display() {
    int i;

    if (rear == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (i = front; i <= MAX; i++)
            printf("%d ", queue[i]);

        for (i = 1; i <= rear; i++)
            printf("%d ", queue[i]);
    }

    printf("\n");
}

// Main function
int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}

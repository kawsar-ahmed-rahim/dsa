//! singly linked list: delete note at certain point using function
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtPosition(struct Node **head, int value, int position) {

    struct Node *newNode = malloc(sizeof(*newNode));

    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(struct Node **head, int position) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node *temp = *head;

    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
}

void display(struct Node *head) {

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head = NULL;

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);
    insertAtPosition(&head, 40, 4);

    deleteAtPosition(&head, 3);

    display(head);

    return 0;
}
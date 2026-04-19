//! doubly linked list: add note at certain point using function
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtPosition(struct Node **head, int value, int position){

    struct Node *newNode = malloc(sizeof(*newNode));
    newNode->data = value;

    if(position == 1){
        newNode->prev = NULL;
        newNode->next = *head;

        if(*head != NULL)
            (*head)->prev = newNode;

        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    for(int i=1; i<position-1 && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void display(struct Node *head){

    while(head != NULL){
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main(){

    struct Node *head = NULL;

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);
    insertAtPosition(&head, 25, 3);

    display(head);

    return 0;
}
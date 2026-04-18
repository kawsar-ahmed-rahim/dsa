//! Singly linked list: Add node at end using function

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int value) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(struct Node *head){

    struct Node *temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeList(struct Node *head){

    struct Node *temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    display(head);

    freeList(head);

    return 0;
}
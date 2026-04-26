//! Singly linked list: add node at beginning using function

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node *head){

    struct Node *temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeList(struct Node **head){

    struct Node *temp;

    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(){

    struct Node *head = NULL;

    insertBeginning(&head, 100);
    insertBeginning(&head, 200);
    insertBeginning(&head, 300);

    display(head);

    freeList(&head);

    return 0;
}
//! singly linked list: add note at certain position using function

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtPosition(struct Node **head, int value, int position){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(position == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    for(int i = 1; i < position - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node *head){

    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
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

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2); 
    insertAtPosition(&head, 30, 3); 

    insertAtPosition(&head, 25, 3); 

    display(head);

    freeList(&head);

    return 0;
}
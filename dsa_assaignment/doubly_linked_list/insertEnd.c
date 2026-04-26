#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertEnd(struct Node **head, int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display(struct Node *head){

    while(head != NULL){
        printf("%d <-> ", head->data);
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

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    display(head);

    freeList(&head);

    return 0;
}
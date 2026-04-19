#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int value){

    struct Node *newNode = malloc(sizeof(*newNode));
    newNode->data = value;

    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

void display(struct Node *head){

    struct Node *temp = head;

    if(head != NULL){
        do{
            printf("%d -> ", temp->data);
            temp = temp->next;
        }while(temp != head);
    }

    printf("HEAD\n");
}

int main(){

    struct Node *head = NULL;

    insertEnd(&head,10);
    insertEnd(&head,20);
    insertEnd(&head,30);

    display(head);

    return 0;
}
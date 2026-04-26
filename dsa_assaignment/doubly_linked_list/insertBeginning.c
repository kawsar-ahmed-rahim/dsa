#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if(*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
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

    insertBeginning(&head, 10);
    insertBeginning(&head, 20);
    insertBeginning(&head, 30);

    display(head);

    freeList(&head);


    return 0;
}
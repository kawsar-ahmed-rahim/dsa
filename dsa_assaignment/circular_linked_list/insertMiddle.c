#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtPosition(struct Node **head, int value, int position){

    struct Node *newNode = malloc(sizeof(*newNode));
    newNode->data = value;

    if(position == 1){

        if(*head == NULL){
            *head = newNode;
            newNode->next = *head;
            return;
        }

        struct Node *last = *head;

        while(last->next != *head)
            last = last->next;

        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    for(int i=1; i<position-1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
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

    insertAtPosition(&head,10,1);
    insertAtPosition(&head,20,2);
    insertAtPosition(&head,30,3);
    insertAtPosition(&head,25,3);

    display(head);

    return 0;
}
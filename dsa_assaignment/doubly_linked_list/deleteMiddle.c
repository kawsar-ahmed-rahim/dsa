//! doubly linked list: delete note at certain point using function
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void deleteAtPosition(struct Node **head, int position){

    if(*head == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node *temp = *head;

    for(int i=1; i<position && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        printf("Invalid Position\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
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

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void deleteEnd(struct Node **head){

    if(*head == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node *temp = *head;

    if(temp->next == NULL){
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
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
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void deleteBeginning(struct Node **head){

    if(*head == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    if(*head != NULL)
        (*head)->prev = NULL;

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

    struct Node *head = malloc(sizeof(struct Node));
    head->data = 10;
    head->prev = NULL;

    head->next = malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->prev = head;
    head->next->next = NULL;

    deleteBeginning(&head);

    display(head);

    return 0;
}
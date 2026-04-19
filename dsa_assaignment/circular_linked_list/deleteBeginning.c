#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void deleteBeginning(struct Node **head){

    if(*head == NULL) return;

    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *last = *head;

    while(last->next != *head)
        last = last->next;

    struct Node *temp = *head;
    *head = (*head)->next;
    last->next = *head;

    free(temp);
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

    return 0;
}
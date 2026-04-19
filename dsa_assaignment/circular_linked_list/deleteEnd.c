#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void deleteEnd(struct Node **head){

    if(*head == NULL) return;

    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    while(temp->next->next != *head)
        temp = temp->next;

    free(temp->next);
    temp->next = *head;
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
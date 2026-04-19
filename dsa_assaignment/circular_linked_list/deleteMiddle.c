#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void deleteAtPosition(struct Node **head, int position){

    if(*head == NULL || position < 1)
        return;

    if(position == 1){

        if((*head)->next == *head){
            free(*head);
            *head = NULL;
            return;
        }

        struct Node *last = *head;

        while(last->next != *head)
            last = last->next;

        struct Node *del = *head;
        *head = (*head)->next;
        last->next = *head;
        free(del);
        return;
    }

    struct Node *temp = *head;

    for(int i=1; i<position-1 && temp->next != *head; i++)
        temp = temp->next;

    if(temp->next == *head)
        return;

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

int main(){

    struct Node *head = NULL;

    return 0;
}
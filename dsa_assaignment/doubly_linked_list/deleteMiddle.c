#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Delete at certain position
void deletePosition(struct Node **head, int position){

    if(*head == NULL){
        printf("List Empty\n");
        return;
    }

    struct Node *temp = *head;
    int i;

    // Delete first node
    if(position == 1){
        *head = temp->next;

        if(*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        return;
    }

    // Move to required position
    for(i = 1; temp != NULL && i < position; i++){
        temp = temp->next;
    }

    // Invalid position
    if(temp == NULL){
        printf("Invalid Position\n");
        return;
    }

    // Link previous node with next node
    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Display list
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

    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->prev = head->next;
    head->next->next->next = NULL;

    deletePosition(&head, 2);   // Delete node at position 2

    display(head);

    return 0;
}
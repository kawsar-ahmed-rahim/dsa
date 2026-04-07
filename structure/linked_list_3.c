//! =============DELETION=============

//! delete node at beginning using function
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteBeginning(struct Node **head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main(){

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = NULL;

    deleteBeginning(&head);

    struct Node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

//! delete node at end using function
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteEnd(struct Node **head) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

int main(){

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = NULL;

    deleteEnd(&head);

    struct Node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

//! delete node at specific position using function
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteAtPosition(struct Node **head, int position) {
    if(*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    if(position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for(int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main(){

    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    deleteAtPosition(&head, 1);

    struct Node *temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}


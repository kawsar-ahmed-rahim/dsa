//! Doubly linked list: create multiple nodes using loop

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main(){

    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *del = NULL;
    int n, i, value;

    printf("Enter Node Numbers: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){

        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode == NULL){
            printf("Memory not available\n");
            return 1;
        }

        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    del = head;

    while(del != NULL){
        temp = del;
        del = del->next;
        free(temp);
    }

    return 0;
}
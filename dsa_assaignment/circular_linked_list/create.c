#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int main(){

    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *del = NULL;
    int n, i, value;

    printf("Enter Node Numbers: ");
    scanf("%d",&n);

    for(i=0; i<n; i++){

        newNode = malloc(sizeof(*newNode));
        printf("Enter value %d: ", i+1);
        scanf("%d",&value);

        newNode->data = value;

        if(head == NULL){
            head = newNode;
            temp = newNode;
            newNode->next = head;
        }
        else{
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    temp = head;

    if(head != NULL){
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
    }

    while(head != NULL && head->next != head){
        temp = head;
        while(temp->next != head)
            temp = temp->next;

        del = head;
        head = head->next;
        temp->next = head;
        free(del);
    }

    if(head != NULL)
        free(head);

    return 0;
}
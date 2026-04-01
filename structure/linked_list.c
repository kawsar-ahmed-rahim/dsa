#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(){
    struct Node *head = NULL;
    // struct Node *newNode;
    head = (struct Node*)malloc(sizeof(struct Node));

    if(head==NULL){
        printf("Memory not available\n");
        return 1;
    }

    head->data = 10;
    head->next = NULL;

    printf("Data: %d\n", head->data);
    printf("address: %d\n", head->next);
    free(head);
}

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head , *second, *third;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    if(head==NULL || second==NULL || third==NULL){
        printf("Memory not available\n");
        return 1;
    }

    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;

    printf("head data: %d\n",head->data);
    printf("second data: %d\n",second->data);
    printf("third data : %d\n",third->data);

    free(head);
    free(second);
    free(third);

};

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(){
    struct Node *head = NULL;

    struct Node *head, *temp, *newNode;
    int i,value;
    for(i=0; i<=5; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(head==NULL){
            printf("Memory not available\n");
        return 1;
        }
        printf("%d",i+1);
        scanf("%d",&value);

        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;

        } else {
            temp->next=newNode;
            temp=newNode;

        }

    };

    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;

    }

    struct Node *del = head;
    while(del!=NULL){
        del=del->next;
        free(del);
    }


}
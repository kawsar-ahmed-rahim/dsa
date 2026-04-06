//! linked_list:creating single node
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
    printf("address: %p\n", (void*)head->next);
    free(head);
}

//! linked_list:creating multiple nodes

#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    
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
    return 0;

};

//! linked_list:creating multiple nodes using loop
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

int main(){
    struct Node *head = NULL, *temp = NULL, *newNode=NULL, *del=NULL;     
    int i,value;
    for(i=0; i<5; i++){
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if(newNode==NULL){
            printf("Memory not available\n");
            return 1;
        }
        printf("%d",i+1);
        scanf("%d",&value);

        newNode->data=value;
        newNode->next=NULL;

        if(head==NULL){
            head=newNode;
            temp = newNode;
        } else {
            temp->next=newNode;
            temp=newNode;
        }
    };

    temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;

    }

    // struct Node *del = head;
    del = head;
    while(del != NULL){
    //struct Node *next = del->next;
    del = del->next;
    free(del);

}
}

// function: add node at starting

void insertBeginning(struct Node *head, int value){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        insertBeginning(&head,100){
            newNode->data = value;
            newNode->next = *head;
            head = newNode;

        }

}
// add node at last
void insertEnd(struct Node head, int value){
    struct Node *newNode = ()
    newNode->data=value;
    newNode->next=NULL;

    struct Node *temp = head;
    while(temp->next=NuLl){
        temp = temp->next;
    }
    temp->next = newNode;

}
// 1.create 100 node
// 2.delete-3 positions
// 3.insert-3 positions
// 4.searching
// 5.double


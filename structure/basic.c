//! student structure

#include <stdio.h>
#include <string.h>

struct Student { // user defined date type
    int roll;
    char name[20];
    float result;

};

int main () {
    // way one
    struct Student s1 = {10, "Rahim", 2.00};

    printf("Roll: %d\n", s1.roll);
    printf("Name: %s\n", s1.name);
    printf("Result: %.2f\n", s1.result);

    printf("\n");

    //way two
    struct Student s2;  

    s2.roll = 20;
    strcpy(s2.name, "safin");   
    s2.result = 3.00;
    
    printf("Roll: %d\n",s2.roll);
    printf("Name: %s\n", s2.name);
    printf("Result: %.2f\n", s2.result);

    printf("\n");

    //way three
    struct Student s3[5];
    s3[0].roll = 30;
    strcpy(s3[0].name, "Karim");
    s3[0].result = 3.50;

    printf("Roll: %d\n",s3[0].roll);
    printf("Name: %s\n", s3[0].name);
    printf("Result: %.2f\n", s3[0].result);

    printf("\n");

    //way four using input from user
    struct Student s4[3];

    for(int i=1; i<3; i++){
        scanf("%d", &s4[i].roll);
        scanf("%s", &s4[i].name);
        scanf("%f", &s4[i].result);
    }
    for(int i=1; i<3; i++){
        printf("Roll: %d\n",s4[i].roll);
        printf("Name: %s\n", s4[i].name);
        printf("Result: %.2f\n", s4[i].result);
        }

        printf("\n");

        //way five using pointer
        struct Student s5;
        struct Student *ptr;
        ptr = &s5;

        scanf("%d", &ptr->roll);
        scanf("%s",&ptr->name); //name is already a character array, so you should not use &.
        scanf("%f", &ptr->result); //An array name already represents the address of its first element.

        printf("Roll: %d\n",ptr->roll);
        printf("Name: %s\n", ptr->name);
        printf("Result: %.2f\n", ptr->result);

        printf("\n");

        //way six using pointer and taking input from user
        struct Student s6[3];
        struct Student *ptr1;
        ptr1 = s6; // But s6 is already an array. In C, an array decays to a pointer to its first element.


        for(int i=0; i<=3; i++){
            scanf("%d", &ptr1[i].roll);
            scanf("%s", &ptr1[i].name);
            scanf("%f", &ptr1[i].result);
        }
        for(int i=0; i<=3; i++){
            printf("Roll: %d\n",ptr1[i].roll);
            printf("Name: %s\n", ptr1[i].name);
            printf("Result: %.2f\n", ptr1[i].result);
        }

        printf("\n");

        //dynamic memory allocation 

            struct Student *ptr2;
            int n;
            printf("Enter the number of students: ");
            scanf("%d", &n);
    
            ptr2 = (struct Student*) malloc(n * sizeof(struct Student));

            if (ptr2 == NULL) {
                printf("Memory not available\n");
                return 1;
    }
    
            for(int i=0; i<n; i++){
                scanf("%d", &ptr2[i].roll);
                scanf("%s", &ptr2[i].name);
                scanf("%f", &ptr2[i].result);
            }

            for(int i=0; i<n; i++){
                printf("Roll: %d\n",ptr2[i].roll);
                printf("Name: %s\n", ptr2[i].name);
                printf("Result: %.2f\n", ptr2[i].result);
            }

        return 0;

};
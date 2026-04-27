// Create an Array Based Stack in C
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int main() {
    int i, value;

    printf("Enter %d elements:\n", MAX);

    for(i = 0; i < MAX; i++) {
        if(top == MAX - 1) {
            printf("Stack Overflow\n");
            break;
        }

        scanf("%d", &value);
        top++;
        stack[top] = value;
    }

    printf("\nStack Elements:\n");

    for(i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    return 0;
}
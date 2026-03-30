//! dynamic memory allocation: sum using malloc function
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n = 5; 
    int *arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory not available\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    free(arr);
    printf("Sum: %d\n", sum);

    
    return 0;
}

//! dynamic memory allocation: average using malloc function

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory not available\n");
        return 1;
    }


    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    float avg;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    avg = (float)sum / n;

    printf("Average = %.2f\n", avg);

    free(arr);

    return 0;
}
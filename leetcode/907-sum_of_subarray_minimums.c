#include <stdio.h>

/******************************************/

#include <stdlib.h>

int sumSubarrayMins(int* arr, int arrSize) {
    int sum = 0;

    /* monotonic increasing stack */
    int *stack = (int *) malloc(sizeof(int) * arrSize);
    int top = -1;
    stack[++top] = 0;

    int i = 1;
    while (i < arrSize) {
        if (top >= 0 && arr[i] <= arr[stack[top]]) {
            sum += arr[i] * (i - stack[top] - 1);
        }
        while (top >= 0 && arr[i] <= arr[stack[top]]) {
            sum += arr[stack[top]] * (i - stack[top]);
            //printf("Retirando do stack\n");
            //printf("top = %d\n", arr[stack[top]]);
            top--;
        }
        stack[++top] = i;
        i++;
    }

    /* now we empty the stack until it has only one element */
    int stack_size = top+1;
    //printf("stack_size = %d\n", top+1);
    while (top >= 1) {
        sum += arr[stack[top]] * (arrSize - stack[top]);
        //printf("Retirando do stack\n");
        //printf("top = %d\n", arr[stack[top]]);
        top--;
    }
    /* the bottom element of the stack is the global minimum */
    sum += arr[stack[top]] * (arrSize + stack_size - 1); /* it is the minimum n arrays not counted yet */
    /* [0, 1, ..., min-1, min] */
    /* [1, ..., min-1, min] */
    /* ... */
    /* [min-1, min] */
    /* [min] */
    /* [min, min+1] */
    /* ... */
    /* [min, min+1, ..., n-1] */
    top--;
    /* now the stack is empty */

    free(stack);
    return sum;
}

/************************************/

int main() {
    int arr[] = { 11,81,94,43,3 };
    int sum = sumSubarrayMins(arr, 5);
    printf("soma final = %d\n", sum);
    return 0;
}

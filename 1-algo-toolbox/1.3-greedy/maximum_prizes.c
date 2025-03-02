#include "header.h"

typedef struct {
    int top;  // stack top
    int *arr; // pointer to the array
} stack;

stack *init_stack() {
    stack *st = (stack *) malloc(sizeof(stack));
    st->top = -1;
    st->arr = NULL;
    return st;
}

void free_stack(stack *st) {
    free(st->arr);
    free(st);
}

void push(stack *st, int x) {
    st->top++;
    st->arr = realloc(st->arr, (st->top + 1) * sizeof(int));
    st->arr[st->top] = x;
}

int pop(stack *st) {
    int x = st->arr[st->top];
    st->top--;
    st->arr = realloc(st->arr, (st->top + 1) * sizeof(int));
    return x;
}

int main() {
    int n, current;
    scanf("%d", &n);
    current = n;
    stack *vec = init_stack();
    int a = 0;
    while (++a <= current) {
        push(vec, a);
        current -= a;
    }
    a = pop(vec);
    push(vec, a+current);
    printf("%d\n", vec->top+1);
    PRINT_ARRAY(vec->arr, vec->top+1, "%d")
    free_stack(vec);
    return 0;
}

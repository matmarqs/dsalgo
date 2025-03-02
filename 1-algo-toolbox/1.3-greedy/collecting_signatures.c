#include "header.h"

typedef struct {
    int l;
    int r;
} segment;

typedef struct {
    int size;   // size of the array, aka initial number of segments
    int top;     // stack pointer
    segment *seg; // pointer to the array
} stack;

stack *alloc_stack(int size) {
    stack *st = (stack *) malloc(sizeof(stack));
    segment *seg = (segment *) malloc(size * sizeof(segment));
    st->size = size;
    st->top = -1;
    st->seg = seg;
    return st;
}

void free_stack(stack *st) {
    free(st->seg);
    free(st);
}

void push(stack *st, segment seg) {
    st->top++;
    st->seg[st->top] = seg;
}

segment pop(stack *st) {
    return st->seg[st->top--];
}

// use to sort segment by left end, in descending order
int cmpLeftEnd(const void *a, const void *b) {
    segment *seg_a = (segment *) a;
    segment *seg_b = (segment *) b;
    return (int)(seg_b->l) - (int)(seg_a->l);
}

void solve(stack *st) {
    int n_points = 0;
    int *x = (int *) malloc(st->size * sizeof(int));    // number of points is at most the number of segments
    segment *fst, *snd = st->seg;
    int max_l, min_r;
    while(st->top != 0) {   // while there is more than one element
        fst = st->seg + st->top;
        snd = st->seg + st->top - 1;
        max_l = MAX(fst->l, snd->l);
        min_r = MIN(fst->r, snd->r);
        if (max_l <= min_r) {   // fst and snd intersect
            // update the snd to be the intersection
            snd->l = max_l;
            snd->r = min_r;
        }
        else {  // they do not intersect
            x[n_points++] = fst->r;  // just append the some valid coordinate
        }
        pop(st);  // decrement the top
    }
    // when leaving the while loop, there is only one element `snd`, and st->top == 0.
    x[n_points++] = snd->r;
    pop(st);    // now the stack is empty (st->top == -1)

    // now we print the results
    printf("%d\n", n_points);
    PRINT_ARRAY(x, n_points, "%d");
    free(x);
}

int main() {
    int n;
    scanf("%d", &n);
    stack *st = alloc_stack(n);
    segment seg;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(seg.l), &(seg.r));
        push(st, seg);
    }
    qsort(st->seg, n, sizeof(segment), cmpLeftEnd);   // sorting the segments by left end in descending order
    solve(st);
    free_stack(st);
    return 0;
}

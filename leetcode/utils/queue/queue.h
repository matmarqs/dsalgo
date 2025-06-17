#include <stdio.h>
#include <stdlib.h>

#define DEFINE_QUEUE(type, name)                                                        \
typedef struct name##_Node {                                                            \
    type data;                                                                          \
    struct name##_Node *next;                                                           \
} name##_Node;                                                                          \
                                                                                        \
typedef struct {                                                                        \
    name##_Node *head;                                                                  \
    name##_Node *tail;                                                                  \
    int size;                                                                           \
} Queue;                                                                                \
                                                                                        \
static name##_Node *name##_create_node(type data) {                                     \
    name##_Node *node = (name##_Node *)malloc(sizeof(name##_Node));                     \
    if (!node) {                                                                        \
        fprintf(stderr, "Memory allocation failed\n");                                  \
        exit(EXIT_FAILURE);                                                             \
    }                                                                                   \
    node->data = data;                                                                  \
    node->next = NULL;                                                                  \
    return node;                                                                        \
}                                                                                       \
                                                                                        \
Queue *name##_init() {                                                                  \
    Queue *q = (Queue *)malloc(sizeof(Queue));                                          \
    if (!q) {                                                                           \
        fprintf(stderr, "Memory allocation failed\n");                                  \
        exit(EXIT_FAILURE);                                                             \
    }                                                                                   \
    q->head = NULL;                                                                     \
    q->tail = NULL;                                                                     \
    q->size = 0;                                                                        \
    return q;                                                                           \
}                                                                                       \
                                                                                        \
int name##_is_empty(Queue *q) {                                                         \
    return q->size == 0;                                                                \
}                                                                                       \
                                                                                        \
type name##_peek(Queue *q) {                                                            \
    if (name##_is_empty(q)) {                                                           \
        fprintf(stderr, "Queue is empty, cannot peek\n");                               \
        exit(EXIT_FAILURE);                                                             \
    }                                                                                   \
    return q->head->data;                                                               \
}                                                                                       \
                                                                                        \
int name##_size(Queue *q) {                                                             \
    return q->size;                                                                     \
}                                                                                       \
                                                                                        \
type name##_dequeue(Queue *q) {                                                         \
    if (name##_is_empty(q)) {                                                           \
        fprintf(stderr, "Queue is empty, cannot dequeue\n");                            \
        exit(EXIT_FAILURE);                                                             \
    }                                                                                   \
    type data = q->head->data;                                                          \
    name##_Node *old_head = q->head;                                                    \
    q->head = q->head->next;                                                            \
    free(old_head);                                                                     \
    q->size--;                                                                          \
    if (q->size == 0) {                                                                 \
        q->tail = NULL;                                                                 \
    }                                                                                   \
    return data;                                                                        \
}                                                                                       \
                                                                                        \
void name##_enqueue(Queue *q, type data) {                                              \
    name##_Node *new_node = name##_create_node(data);                                   \
    if (name##_is_empty(q)) {                                                           \
        q->head = new_node;                                                             \
        q->tail = new_node;                                                             \
    } else {                                                                            \
        q->tail->next = new_node;                                                       \
        q->tail = new_node;                                                             \
    }                                                                                   \
    q->size++;                                                                          \
}                                                                                       \
                                                                                        \
void name##_free(Queue *q) {                                                            \
    while (q->head) {                                                                   \
        name##_Node *current = q->head;                                                 \
        q->head = q->head->next;                                                        \
        free(current);                                                                  \
    }                                                                                   \
    free(q);                                                                            \
}

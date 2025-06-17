#include <stdio.h>
#include <stdlib.h>

#define DEFINE_QUEUE(type, name)                                                        \
typedef struct Node {                                                                   \
    type data;                                                                          \
    struct Node *next;                                                                  \
} Node;                                                                                 \
                                                                                        \
typedef struct {                                                                        \
    Node *head;                                                                         \
    Node *tail;                                                                         \
    int size;                                                                           \
} Queue;                                                                                \
                                                                                        \
static Node *name##_create_node(type data) {                                            \
    Node *node = (Node *)malloc(sizeof(Node));                                          \
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
type name##_peek(Queue *q) {                                                            \
    if (!q->head) {                                                                     \
        fprintf(stderr, "Queue is empty\n");                                            \
        exit(EXIT_FAILURE);                                                             \
    }                                                                                   \
    return q->head->data;                                                               \
}                                                                                       \
                                                                                        \
int name##_is_empty(Queue *q) {                                                         \
    return q->size == 0;                                                                \
}                                                                                       \
                                                                                        \
void name##_dequeue(Queue *q) {                                                         \
    if (name##_is_empty(q)) {                                                           \
        fprintf(stderr, "Queue is empty, cannot dequeue\n");                            \
        exit(EXIT_FAILURE);                                                             \
    }                                                                                   \
    Node *old_head = q->head;                                                           \
    q->head = q->head->next;                                                            \
    free(old_head);                                                                     \
    q->size--;                                                                          \
    if (q->size == 0) {                                                                 \
        q->tail = NULL;                                                                 \
    }                                                                                   \
}                                                                                       \
                                                                                        \
void name##_enqueue(Queue *q, type data) {                                              \
    Node *new_node = name##_create_node(data);                                          \
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
        Node *current = q->head;                                                        \
        q->head = q->head->next;                                                        \
        free(current);                                                                  \
    }                                                                                   \
    free(q);                                                                            \
}

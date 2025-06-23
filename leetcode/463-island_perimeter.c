#include <stdbool.h>

/*******************************************************************/

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
    Node *old_head = q->head;                                                           \
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

typedef struct Point {
    int i;
    int j;
} Point;

DEFINE_QUEUE(Point, queue);

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    /* find first island */
    Point first;
    bool found_first = false;
    int i = 0;
    while (!found_first && i < gridSize) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == 1) {
                found_first = true;
                first.i = i;
                first.j = j;
                break;
            }
        }
        i++;
    }

    /* init queue and enqueue first island */
    Queue *q = queue_init();
    queue_enqueue(q, first);
    grid[first.i][first.j] = 2; // 2 means already queued

    int perimeter = 0;

    /* bread-first search */
    while (!queue_is_empty(q)) {
        Point island = queue_dequeue(q);

        /* each island has perimeter = 4 - num_of_neighboring_islands */
        perimeter += 4;

        if (island.i-1 >= 0 && grid[island.i-1][island.j] == 1) {
            queue_enqueue(q, (Point) {island.i-1, island.j});
            grid[island.i-1][island.j] = 2;  // queued
            perimeter--;
        }
        else if (island.i-1 >= 0 && grid[island.i-1][island.j] == 2) {
            perimeter--;
        }

        if (island.j-1 >= 0 && grid[island.i][island.j-1] == 1) {
            queue_enqueue(q, (Point) {island.i, island.j-1});
            grid[island.i][island.j-1] = 2;  // queued
            perimeter--;
        }
        else if (island.j-1 >= 0 && grid[island.i][island.j-1] == 2) {
            perimeter--;
        }

        if (island.i+1 < gridSize && grid[island.i+1][island.j] == 1) {
            queue_enqueue(q, (Point) {island.i+1, island.j});
            grid[island.i+1][island.j] = 2;  // queued
            perimeter--;
        }
        else if (island.i+1 < gridSize && grid[island.i+1][island.j] == 2) {
            perimeter--;
        }

        if (island.j+1 < *gridColSize && grid[island.i][island.j+1] == 1) {
            queue_enqueue(q, (Point) {island.i, island.j+1});
            grid[island.i][island.j+1] = 2;  // queued
            perimeter--;
        }
        else if (island.j+1 < *gridColSize && grid[island.i][island.j+1] == 2) {
            perimeter--;
        }
    }

    queue_free(q);

    return perimeter;
}

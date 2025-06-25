struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*******************************************************/

#include <stdlib.h>

typedef struct Stack {
    int *array;
    int top;
    int size;
} Stack;

int inOrderTraversal(struct TreeNode *root, int current_freq, int *max_freq) {
    if (!root)
        return current_freq;

    inOrderTraversal(root->left, current_freq, max_freq);

    if (root->left && root->val == root->left->val) {
        current_freq++;
    }

    inOrderTraversal(root->right, current_freq,  max_freq);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->size = 2;
    stack->array = (int *) malloc(sizeof(int) * stack->size);
    stack->top = -1;

    int max_freq = 0;
    inOrderTraversal(root, 0, &max_freq);


    *returnSize = stack->top + 1;
    return stack->array;
}

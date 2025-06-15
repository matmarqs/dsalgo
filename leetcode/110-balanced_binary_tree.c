#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/************************************************************/

#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int height(struct TreeNode *node) {
    if (!node) return 0;
    int left_height = height(node->left);
    int right_height = height(node->right);
    return max(left_height, right_height) + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (!root)
        return true;

    int left_height = height(root->left);
    int right_height = height(root->right);

    return abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

/************************************************************/

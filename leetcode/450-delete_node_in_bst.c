struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode *parent_of_next_right(struct TreeNode *node) {
    if (!node) {
        return NULL;
    }
    if (!node->right) {
        return node;
    }
    struct TreeNode *parent = node;
    node = parent->right;
    while (node->left) {
        parent = node;
        node = parent->left;
    }
    return parent;
    /* if parent == arg_node, out_node = parent->right */
    /* if parent != arg_node, out_node = parent->left  */
}

/* let's do preOrderTraversal, why not? */
struct TreeNode* find(struct TreeNode* root, int key) {
    if (!root) {
        return NULL;
    }
    if (key == root->val) {
        return root;
    }
    else if (key < root->val) {
        return find(root->left, key);
    }
    else {
        return find(root->right, key);
    }
}

/* let's do preOrderTraversal, why not? */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode *node_to_delete = find(root, key);
    if (!node_to_delete)
        return root;

    struct TreeNode *parent_next_right = parent_of_next_right(node_to_delete);

    if (parent_next_right == node_to_delete) {
        /* in this case, next_right = parent->right */
        struct TreeNode *next_right = parent_next_right->right;
        if (next_right) {
        }
        else {
            /* there is no next_right */
        }
    }

    if (root->val) {
        free(root);
    }

    deleteNode(root->left, key);
    deleteNode(root->right, key);
}

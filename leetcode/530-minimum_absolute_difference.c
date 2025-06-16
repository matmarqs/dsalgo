struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*******************************************************************************/

/* this code is wrong, because it only checks diff between parent and its children */
/* but the minimum diff can occur between non-adjacent nodes */
/* 
 * For example, the minimum diff below is 9-8 = 1
 *
 *      9
 *    /   \
 *   5     14
 *    \
 *     8
 *
 * */

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define MYMAX 100001 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root) {
    int diff_left = (root->left) ? (root->val - root->left->val) : MYMAX;
    int diff_right = (root->right) ? (root->right->val - root->val) : MYMAX;

    if (root->left) {
        diff_left = min(diff_left, getMinimumDifference(root->left));
    }
    if (root->right) {
        diff_right = min(diff_right, getMinimumDifference(root->right));
    }

    return min(diff_left, diff_right);
}

/* Time Limit Exceeded */
#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }

    return (maxDepth(root->left) > maxDepth(root->right) ?
            maxDepth(root->left) : maxDepth(root->right)) + 1;
}

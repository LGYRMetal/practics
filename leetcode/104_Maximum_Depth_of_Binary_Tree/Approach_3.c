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
    int liftDepth = 0;
    int rightDepth = 0;

    if(root == NULL) {
        return 0;
    }
    /*
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    */

    liftDepth = maxDepth(root->left);
    rightDepth = maxDepth(root->right);

    return (liftDepth > rightDepth ? liftDepth : rightDepth) + 1;

    /*
    return (maxDepth(root->left) > maxDepth(root->right) ?
            maxDepth(root->left) : maxDepth(root->right)) + 1;
    */
}

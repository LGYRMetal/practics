/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root && (root->left || root->right)) {
        root->left = (struct TreeNode*)((int)root->left ^ (int)root->right);
        root->right= (struct TreeNode*)((int)root->left ^ (int)root->right);
        root->left = (struct TreeNode*)((int)root->left ^ (int)root->right);

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
    }

    return root;
}

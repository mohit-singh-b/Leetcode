/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void invert(struct TreeNode* root);
struct TreeNode* invertTree(struct TreeNode* root) {
    invert(root);
    return root;
}

void invert(struct TreeNode* root){
    if ( root == NULL)
        return;

    struct TreeNode* temp = NULL;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    invert(root->left);
    invert(root->right);

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int dep( struct TreeNode* root );
int maxDepth(struct TreeNode* root) {
    return dep(root);
}

int dep( struct TreeNode* root ){
    if (root == NULL){
        return 0;
    }

    int d1 = dep(root->left);
    int d2 = dep(root->right);

    return 1+(d1>d2 ? d1 : d2);
}

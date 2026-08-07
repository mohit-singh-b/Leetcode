/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool check(struct TreeNode* root,struct TreeNode* root2 );
bool isSymmetric(struct TreeNode* root) {
    if ( root->left == NULL && root->right== NULL ){
        return true;
    }
    if(root->left == NULL || root->right== NULL)
        return false;
    if ( root->left->val != root->right->val )
        return false;

    return check(root->left,root->right);
}

bool check(struct TreeNode* root,struct TreeNode* root2 ){
    if (root == NULL && root2 == NULL ){
        return true;
    }
    if(root == NULL || root2 == NULL)
        return false;
    

    if(root->val != root2->val)
        return false;

    return check(root->left,root2->right) && check(root->right,root2->left);
}
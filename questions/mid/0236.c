/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    if ( root == NULL)
        return NULL;

    if ( root== p ) 
        return p;
    if (root == q) 
        return q;

    struct TreeNode *l = lowestCommonAncestor(root->left,p,q), *r = lowestCommonAncestor(root->right,p,q);

    if ( l && r)
        return root;
    else if ( l || r)
        return l ? l : r;

    return NULL;
    
}


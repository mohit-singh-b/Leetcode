/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void traverse(struct TreeNode* root, struct TreeNode* subroot,int *b);
 bool check(struct TreeNode* root, struct TreeNode* subroot);
bool isSubtree(struct TreeNode* root, struct TreeNode* subroot) {
    int b=0;

     if ( root == NULL && subroot == NULL)
        return true;
    if (root == NULL && subroot != NULL)
        return false;
    if(root != NULL && subroot == NULL)
        return true;

    traverse(root,subroot,&b);
    return b;
}
void traverse(struct TreeNode* root, struct TreeNode* subroot,int *b){
    if(*b)
        return;
    if (root == NULL)
        return;

    if ( root->val == subroot->val ){
        if(check(root,subroot)) {
            *b=1;return;
        }
    }

    traverse(root->left,subroot,b);
    traverse(root->right,subroot,b);


}
bool check(struct TreeNode* root, struct TreeNode* subroot){
    if ( root == NULL && subroot == NULL)
        return true;
    if(root == NULL || subroot == NULL )
        return false;
    if(root->val != subroot->val)
        return false;

       
    return check(root->left,subroot->left) && check(root->right,subroot->right);
    
}
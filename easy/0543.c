/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int depth(struct TreeNode* root,int *m);
int diameterOfBinaryTree(struct TreeNode* root) {
    int max = 0 ;
    depth(root,&max);
    return max;
}

int depth(struct TreeNode* root,int *m){
    if ( root == NULL)
        return 0;
    int d1,d2;
    d1 = depth(root->left,m);
    d2 = depth(root->right,m);

    int dia = d1+d2;
    *m = (*m) < dia ? dia : (*m);

    return 1 + (d1 > d2 ? d1 : d2);
}
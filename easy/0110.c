/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int bal(struct TreeNode* root,int *md);
bool isBalanced(struct TreeNode* root) {
    int md = 0;
    bal(root,&md);
    
    return md < 2;
}

int bal(struct TreeNode* root,int *md){
    if(root == NULL)
        return 0;
        
    if ( *md > 1 )
        return *md;

    int d1 = bal(root->left,md);
    int d2 = bal(root->right,md);
    int d ;

    d = d2 > d1 ? d2 -d1 : d1 -d2;
    *md = d > (*md) ? d : (*md);



    return 1 + (d2 > d1 ? d2 : d1);


}


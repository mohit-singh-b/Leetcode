/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;
Node* tree(int* inorder, int* preorder ,int s , int e , int* k );
struct TreeNode* buildTree(int* preorder, int n, int* inorder, int inorderSize) {
   int k = 0;
    return tree(inorder,preorder,0,n-1,&k);

}

Node* tree(int* inorder, int* preorder ,int s , int e , int* k ){
    int i =0;

    if ( s > e )
        return NULL;

    Node *node = calloc(1,sizeof(Node));
    node->val = preorder[*k];
    (*k)++;

    if ( s == e )
        return node ;

    for ( i = s ; i <=  e ; i++ ){
        if ( inorder[i] == node->val)
            break;
    }

    node->left = tree(inorder,preorder,s,i-1,k);
    node->right = tree(inorder,preorder,i+1,e,k);

    return node;

}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **res = malloc(2000*sizeof(int*));
    int size = 0;
    struct TreeNode** queue = malloc(1500*sizeof(struct Treenode*));
    *returnColumnSizes = malloc(2020*sizeof(int));
    int tail = 0 , head = 0,i=0,j=0,k=0 ;
    struct TreeNode* temp;        


    if ( root == NULL){
        *returnSize = 0;
        return NULL;
    }

    queue[(tail++)%1500] = root;
    queue[(tail++)%1500]=NULL;
    size+=2;
    res[i] = malloc(2*sizeof(int));

    while ( size != 0){

        if ( queue[head%1500] == NULL && queue[(tail-1)%1500] == NULL){
            (*returnColumnSizes)[i] = j;
            i++;
            break;
        }
        if ( queue[head%1500] == NULL){
            head++;
            queue[(tail++)%1500] = NULL;
            size++;
            (*returnColumnSizes)[i] = j;
            res[++i] = malloc(1000*sizeof(int));
            j=0;
            continue;
        }

        temp = queue[(head++)%1500];
        size--;
        if ( temp->left != NULL){ queue[(tail++)%1500] = temp->left;size++;}
        if ( temp->right != NULL ){queue[(tail++)%1500] = temp->right;size++;}

        res[i][j++] = temp->val; 

    }
    *returnSize = i;
    return res;

    
}
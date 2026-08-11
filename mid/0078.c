/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void sub(int **returnC ,int **res , int *idx,int* nums , int n );
int** subsets(int* nums, int n, int* returnSize, int** returnColumnSizes) {
    int size = pow(2,n), idx = 0 ;
    int **res = malloc(size*sizeof(int*));
    res[idx++] = NULL;
    *returnColumnSizes = malloc(size*sizeof(int*));
    (*returnColumnSizes)[0] = 0;

    sub(returnColumnSizes,res,&idx,nums,n);
    *returnSize = idx;
    return res;

}

void sub(int **returnC ,int **res , int *idx,int* nums , int n ){

    if ( n == 1 ){
        res[(*idx)] = malloc(sizeof(int));
        *res[(*idx)] = nums[0];
        (*returnC)[(*idx)++] = 1;
        return;       

    }
    sub(returnC,res ,idx,nums,n-1);
    int len , e , j,i ,index = *idx;

    for (  i = 0 ; i < index ; i++){
        len = (*returnC)[i];
        res[(*idx)] = malloc((len+1)*sizeof(int));
        (*returnC)[(*idx)] = len+1;


        for ( j = 0 ; j < len ; j++){
            res[*idx][j] = res[i][j];
        }
        res[(*idx)++][len] = nums[n-1];

    }
    return;
}
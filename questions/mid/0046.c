/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void backtrack(int**res , int** returnColumnSizes , int *a , int *idx , int n , int j );
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int fact=1 ,idx = 0 ; 
    for ( int i = 1  ; i <= numsSize ; i++)
        fact*=i;
       
    int **res = malloc(fact*sizeof(int*));
    *returnColumnSizes = malloc(fact*sizeof(int*));


    backtrack(res,returnColumnSizes,nums,&idx,numsSize,0);
    *returnSize = idx;
    return res;

}

void backtrack(int**res , int** returnColumnSizes , int *a , int *idx , int n , int j ){

    if ( j == n){
        res[*idx] = malloc(n*sizeof(int));
        (*returnColumnSizes)[*idx] = n;
        memcpy(res[*idx],a,n*sizeof(int));
        (*idx)++;
        return ;

    }
    
    int temp ;

    for ( int i = j ; i < n ; i ++){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
        
        backtrack(res,returnColumnSizes,a,idx,n,j+1);

         temp = a[j];
        a[j] = a[i];
        a[i] = temp;

        
    }
}
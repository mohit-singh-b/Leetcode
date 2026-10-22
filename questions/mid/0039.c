/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void backtrack(int *nums , int **res , int **rcs , int *idx , int *a , int alen , int n , int i , int sum ,int target );
int** combinationSum(int* nums, int n, int target, int* returnSize, int** rcs) {
    int **res = malloc(150*sizeof(int*)),idx = 0;
    *rcs = malloc(150*sizeof(int));
    int a[150];
    backtrack(nums,res,rcs,&idx,a,0,n,0,0,target);
    *returnSize = idx;
    return res;

}

void backtrack(int *nums , int **res , int **rcs , int *idx , int *a , int alen , int n , int i , int sum ,int target ){
    if ( sum == target ){
        res[*idx] = malloc(alen*(sizeof(int)));
        (*rcs)[*idx] = alen;
        memcpy(res[*idx],a,alen*sizeof(int));
        (*idx)++;
        return;
    }

    if ( i == n || sum > target ){
        return ;
    }

    a[alen++] = nums[i];
    sum+=nums[i];

    backtrack(nums,res,rcs,idx,a,alen,n,i,sum,target);
    alen--;
    sum-=nums[i];
    backtrack(nums,res,rcs,idx,a,alen,n,i+1,sum,target);

    return ;
}
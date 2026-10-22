/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize ;
    int sum = 0 ;
    int *ans = calloc( numsSize , sizeof(int));

    for ( int i = 0 ; i < numsSize ; i++)
    {
        sum+=nums[i];
        ans[i] = sum;

    }

    return ans;
}
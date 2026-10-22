/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize  = numsSize ;
    int i = 0 , j = numsSize-1 , k = numsSize-1;
    int* p = calloc( numsSize , sizeof(int));

    while (1)
    {
          if ( i == j)
        {
            p[k] = nums[i]*nums[i];
            break;
        }
        
        if ( nums[i]*nums[i] > nums[j]*nums[j]  )
        {
            p[k] = nums[i]*nums[i];
            i++;
        }
        else 
        {
            p[k] = nums[j]*nums[j];
            j--;
        }

        k--;
      
    }
    return p;
}
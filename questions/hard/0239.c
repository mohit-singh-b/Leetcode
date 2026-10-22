/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int head = 0 , tail = 0 ,size =0, i ;
    int *queue = malloc((numsSize)*sizeof(int));
    int *res = malloc(numsSize*sizeof(int));
    *returnSize = numsSize-k+1;

    for ( i = 0 ; i < numsSize ; i++){
       
        if ( size != 0 && i >= k){
       
            res[i-k] = nums[queue[head%numsSize]];
            if ( queue[head] == i-k)
            { head = (head+1)%numsSize;
                size--;}
        }
        while( size != 0 && nums[queue[tail-1]] <= nums[i]){
            tail--;
            size--;
        }
        queue[(tail++)%numsSize] = i;
        size++;

              
    }

    res[i-k] = nums[queue[head%numsSize]]; 

    return res;
}
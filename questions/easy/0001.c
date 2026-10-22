/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 typedef struct{
    int index;
    bool occupied;
 }Hash ;
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int size ,key , keyj, j =0 ;
    size = numsSize*2 +1;
    
    Hash* hash = calloc(size , sizeof(Hash));
    int * p = malloc(2*sizeof(int));

    for ( int i = 0 ; i< numsSize; i++)
    {
        key = nums[i]%size;

        if ( key < 0)
            key+=size;

        while(1)
        {
            if(hash[key].occupied)
            {
                key = (key+1)%size;
            }
            else
            break;
        }

        j = target - nums[i];
        keyj = j%size;

        if ( keyj < 0)
            keyj+=size;

        while(1)
        {
            if(hash[keyj].occupied)
            {
                if( nums[hash[keyj].index] != j)
                keyj = (keyj+1)%size;
                else 
                {
                    p[0] = i ;
                    p[1] = hash[keyj].index;
                    break;
                }
            }
            else
            break;
        }

        hash[key].index = i;
        hash[key].occupied = true;

    }

    return p ;

}
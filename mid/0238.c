/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int sp = 1 , pp = 1 ;
    int *es = malloc(numsSize*sizeof(int));
    *returnSize = numsSize ;

    int *p = calloc(numsSize , sizeof(int));
    int *s = calloc(numsSize , sizeof(int));

    for ( int i = 0 ; i < numsSize ; i++)
    {
        pp*=nums[i];
        sp*=nums[numsSize-1-i]; 
        p[i] = pp;
        s[i] = sp;
    }

    for ( int i = 0 ; i < numsSize ; i++)
    {
        if ( i == 0 )
            es[0] = s[numsSize-2];
        else if ( i == numsSize-1 )
            es[numsSize -1] = p[numsSize-2];
        else
            es[i] = p[i-1]*s[numsSize-2-i];
    }

    free(p);
    free(s);
    return es;
    

}
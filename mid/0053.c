int maxSubArray(int* nums, int numsSize) {
    int max = nums[0] , cs = 0;

    for (  int i = 0 ; i < numsSize ; i++)
    {
        if ( cs < 0)
            cs = nums[i];
        else 
            cs += nums[i];

        if ( cs > max)
            max = cs ;

    }

    return max ;
}
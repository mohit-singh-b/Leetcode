int rob(int* nums, int numsSize) {
    int max = 0 , i ;
    int *dp  = malloc(numsSize*sizeof(int));

    for ( i = 0 ; i < numsSize ; i++){

        dp[i] = nums[i] + max;

        if ( i >0)
            max = dp[i-1] > max ? dp[i-1] : max;
    }
    max = dp[i-1] > max ? dp[i-1] : max;

    return max ;
}
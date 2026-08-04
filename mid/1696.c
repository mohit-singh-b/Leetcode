int maxResult(int* nums, int numsSize, int k) {
    int head = 0 , tail = 0 , i , max ;
    int *dp = malloc(numsSize*sizeof(int));
    int *dq = malloc(numsSize*sizeof(int)); 
    dp[0] = nums[0];

    for ( i = 0 ; i < numsSize ; i++){

       
        if ( head != tail && dq[head] < i-k)
            head++;

        if (head != tail )
            dp[i] = dp[dq[head]] + nums[i];
        else 
            dp[i] = nums[i];


        while( head != tail && dp[i] >= dp[dq[tail-1]]){
            tail--;
        }
        dq[tail++] = i;
    }

 
    return dp[numsSize-1];
}
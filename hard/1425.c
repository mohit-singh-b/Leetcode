int constrainedSubsetSum(int* nums, int numsSize, int k) {
    int i , j , max = nums[0] ,head = 0 , tail = 0 ;
    int *dp = malloc(numsSize*sizeof(int));
    int *dq = malloc(numsSize*sizeof(int));


    for ( i = 0 ; i < numsSize ; i++){

      
        if (head != tail && i-k-1 == dq[head] ){
            head++;
        }

        if ( head != tail && dp[dq[head]] >= 0 ){
            dp[i] = nums[i]+dp[dq[head]];

        }
        else 
            dp[i] = nums[i];
        

        while( head != tail && dp[i] >= dp[dq[tail-1]]){
            tail--;
        }

        dq[tail++] = i;
        max = max > dp[i] ? max : dp[i];

    }

    return max;
}
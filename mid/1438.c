int abs( int a );

int longestSubarray(int* nums, int numsSize, int limit) {
    int i , j = 0 , head = 0 , tail = 0 , headb = 0 , tailb = 0 , max = 0 ;
    int *dq = malloc(sizeof(int)*numsSize);
    int *dqb = malloc(sizeof(int)*numsSize);

    for ( i = 0 ; i < numsSize ; i++){
      
        while ( head != tail && abs(nums[i] - nums[dq[head]] ) > limit ){

            while(j <= dq[head]){
                j++;
            }
            head++;
        }

        while ( headb != tailb && abs(nums[i] - nums[dqb[headb]] ) > limit ){

            while(j <= dqb[headb]){
                j++;
            }
            headb++;
        }

        int len = i-j+1;
        max = max < len ? len : max;

        while(head != tail && nums[i] <= nums[dq[tail-1]]){
            tail--;
        }
        while(headb != tailb && nums[i] >= nums[dqb[tailb-1]]){
            tailb--;
        }

        dq[tail++] = i;
        dqb[tailb++] = i;
    }

    return max;
}

int abs( int a ){
    if ( a  >= 0 )
        return a;
    return -a;
}
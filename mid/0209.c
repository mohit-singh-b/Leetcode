int minSubArrayLen(int target, int* nums, int numsSize) {
    int i= 0 , sum =0, j =0, min = numsSize+1 , len = 1;
    
    for ( j = 0 ; j < numsSize ; j++){
        sum+=nums[j];
        while( sum >= target){
            min = min > len ? len : min;
            len--;
            sum-=nums[i];
            i++;
        }
        len++;
    }
    
    if ( min == numsSize + 1){
        return 0;
    }
    return min;
}
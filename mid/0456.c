bool find132pattern(int* nums, int numsSize) {
    int min , i , j, top = -1 ;
    int *stack = calloc(numsSize , sizeof(int));
    int *s = calloc(numsSize,sizeof(int));

    s[0] = nums[0];
    min = nums[0];
    for ( i = 1 ; i < numsSize ; i++){
        s[i] = min;
        min = min > nums[i] ? nums[i] : min;
    }


    for ( i = 0 ; i < numsSize ; i++){
        
        if ( nums[i] <= s[i]){
            continue;
        }
        
        while(top != -1 && nums[i] >= nums[stack[top]]){
            top--;
        }

        if (top != -1 &&  nums[i] < nums[stack[top]] && nums[i] > s[stack[top]] ){
            return true;
        }
        
        stack[++top] = i;
    }
    return false;



}
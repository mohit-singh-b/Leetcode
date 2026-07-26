int firstMissingPositive(int* nums, int numsSize) {
    int i , n = numsSize , e , temp ,j=0;

    while ( j < n)
    {   e = nums[j]-1;
        if ( nums[j] >= j+1)
            j++;
        else if ( nums[j] <= 0)
            j++;
        else {
            temp = nums[j];
            nums[j] = nums[e];
            nums[e] = temp; 
            if( nums[j] <= numsSize && nums[j] < j+1 && nums[j] != temp){// handles the edge case where the swapped number is also a valid number and less then j , so we dont j++
 
                continue; }
            j++;
        }
    }

    for ( i = 0 ; i < n  ; i++)
        {
            if ( nums[i] != i+1)
                return i+1;
        
        }

    return n+1;

}

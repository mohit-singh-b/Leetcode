int removeDuplicates(int* nums, int numsSize) {

    int i, j = -1,k=1;

    for (i = 1; i < numsSize; i++) 
    {
        if ( nums[i] != nums[i-1])
        {
            k++;
            if ( j!=-1)
                nums[j] = nums[i] , j++;
        }
        else 
        {
            if ( j == -1)
                j=i;
        }
    }

return k;

    }
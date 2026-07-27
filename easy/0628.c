int maximumProduct(int* nums, int numsSize) {
    int max=-2000 , max2=-2000  , max3=-2000  , min2=2000 ,min1=2000 , prod , prod2;

    for ( int i =  0 ; i < numsSize ; i ++){
        if ( nums[i] > max){
            max3 = max2;
            max2=max;
            max = nums[i];
        }
        else if ( nums[i] > max2)
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if( nums[i] > max3)
        {
            max3 = nums[i];
        }

         if ( nums[i] < min1 )
        {
            min2 = min1 ;
            min1 = nums[i];
        }
        else if ( nums[i] < min2 )
        {
            min2 = nums[i];
        }
    }
    printf("%d %d %d %d %d",min1,min2,max3,max2,max);

    prod = max3*max2*max ;
    prod2 = max*min1*min2;

    return prod > prod2 ? prod : prod2 ;
}


typedef struct{
    int value , count;
} Hash;

int maximumUniqueSubarray(int* nums, int numsSize) {
    
    int i= 0 , j = 0 , max , sum = 0 , size , key , keyj , b;
    size = numsSize*2 +1 ;
    max = nums[i];
    Hash *hash = calloc(size , sizeof(Hash));

    while(i<numsSize)
    {
        key = nums[i]%size;

        if(key < 0)
            key+=size;


        while(1)
        {
            if( hash[key].count != 0 )
            {
                if(hash[key].value == nums[i])
                {
                    
                    while(nums[j] != nums[i])
                    {   
                        keyj = nums[j]%size ; 
                        while(1)
                        {
                            if(hash[keyj].value != nums[j])
                                keyj=(keyj+1)%size;
                            else
                            break;
                        }
                        hash[keyj].count--;
                        sum-=hash[keyj].value;
                        j++;
                        
                    }
                    j++;
                    i++;
                    break;
                


                }
                else 
                    key = (key+1)%size;
            }
            else
            {
                hash[key].count ++;
                sum+=nums[i];
                hash[key].value = nums[i];
                i++;
                 if ( sum > max)
                            max = sum;
                break;
            }
           
        }


    }
    return max;

}
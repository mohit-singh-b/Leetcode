typedef struct{
    int counter, sum ;
} Hash;

int subarraySum(int* nums, int numsSize, int k) {
    int sumj = 0 , sum = 0 , c =0  , key , size , keyj;
    size = 2*numsSize + 1;
    Hash *hash = calloc(size , sizeof(Hash));
    

    hash[0].counter =1 ;
    for ( int i = 0 ; i < numsSize ; i++)
    {
        sum+=nums[i];
        key = sum%size;

        if ( key < 0)
            key+=size;
        

        sumj = sum - k ;
        keyj = sumj%size;
        if ( keyj < 0)
            keyj+=size;

        while (1)
        {
            if(hash[keyj].counter )
            {
                if(hash[keyj].sum != sumj)
                    keyj = (keyj+1)%size;
                else
                break;
                    
            }
            else 
            break;

        }


        if ( hash[keyj].counter  != 0)
            c+= hash[keyj].counter;

        while (1)
        {
            if(hash[key].counter )
            {
                if(hash[key].sum != sum)
                    key = (key+1)%size;
                else
                break;
                    
            }
            else 
            break;

        }

        hash[key].counter++;
        hash[key].sum = sum;


    }
    free(hash);
    return c;
}
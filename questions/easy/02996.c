typedef struct Hash{
    int val;
    UT_hash_handle hh;
}Hash;

int missingInteger(int* nums, int numsSize) {
    int sum = nums[0], i , j ;
    Hash *hash = NULL , *temp ;



    for ( i = 1 ; i < numsSize ; i++){
        if ( nums[i] == nums[i-1]+1)
            sum+=nums[i];
        else 
            break;
    }
    if ( i == 1)
        sum++;

    for ( ; i < numsSize ; i++){
        temp = malloc(sizeof(Hash));
        temp->val = nums[i];
        HASH_ADD_INT(hash,val,temp);
    }

    while ( 1){
        HASH_FIND_INT(hash,&sum,temp);
        if ( temp == NULL)
            return sum;
        else 
            sum++;
    }
}

bool check(int*nums,int numsSize , int k ,int max);

int splitArray(int* nums, int numsSize, int k) {
    int l , u , mid ,sum=0, max = nums[0];
    for ( int i = 0 ; i < numsSize ; i++){
        max = max < nums[i] ? nums[i] : max;
        sum+=nums[i];}

    

    l = max;
    u = sum;

    while(u > l){
        mid = (u+l+1)/2;
        printf("(%d,%d) mid : %d\n",l,u,mid);

        if(check(nums,numsSize,k,mid)){
            u=mid-1;}
        else {
            l=mid;}
    }

    for ( int j = 2 ; j < 6;j++){
        if (check(nums,numsSize,k,j))
            printf("(%d,true)\n",j);
    }


    return l;
}

bool check(int *nums,int numsSize , int k , int max){
    int sec=1,cs=0;
    for ( int i = 0 ; i < numsSize ; i++){
        cs+=nums[i];
        if ( cs >= max){
           cs = nums[i];
           
            sec+=1;}
       
    }
    if ( sec <= k)
        return true;
    else 
        return false;
}
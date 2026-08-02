int shortestSubarray(int* nums, int numsSize, int k) {
    int cs = 0 , i = 0 , head = 0 , tail = 0 , size = 0 ,max = 0 ,len=0,min = numsSize+1; 
    int *dq = malloc((numsSize+1)*sizeof(int));
    int *c = malloc((numsSize+1)*sizeof(int));

    c[0] = 0;
    for ( i = 0 ; i < numsSize ; i++){
        cs+=nums[i];
        c[i+1] = cs;
    }

    for ( i = 0 ; i < numsSize+1 ; i++){
        max = c[i]-  k;

        while(size != 0 && c[dq[(tail-1)%numsSize]] >= c[i]){
            tail--;
            size--;
        }
       

        while( size!= 0 && c[dq[head]] <= max ){
            len = i-dq[(head)%numsSize];
            head++;
            size--;
            min = min > len ? len : min ;
        }



        dq[(tail)%numsSize] = i;
        tail++;
        size++;
    }

    return min != numsSize+1 ? min : -1;
}
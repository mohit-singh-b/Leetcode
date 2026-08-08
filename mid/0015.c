/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int compare(const void* a , const void *b);
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums,numsSize,sizeof(int),compare);
    int size = 2*numsSize;
    int i = 0 , j = 0 , k = 0 ,target = 0,e=0;
    int **res = malloc(size*sizeof(int*));

    for ( k = 0 ; k < numsSize-2 ; k++){
        i=k+1;        
        j=numsSize-1;
        if ( k > 0 && nums[k-1] == nums[k])
            continue;
       

        while(i < j){
           if ( nums[i] + nums[j] + nums[k] == 0){
                 if ( e >= size ){
                    res = realloc(res,size*2*sizeof(int*));
                    size*=2;
                 }
                res[e] = malloc(3*sizeof(int));
                res[e][0] = nums[k];
                res[e][1] = nums[i];
                res[e++][2] = nums[j];
                j--;i++;
                while(i < j && nums[j] == nums[j+1])j--;
                while(i < j && nums[i-1] == nums[i])i++;
                continue;
           }

           if ( nums[i]+nums[j] + nums[k] < 0)
                i++;
            else 
                j--;
        }
    }

    *returnSize = e;
    *returnColumnSizes = malloc(e*sizeof(int));
    for ( i = 0 ; i < e ; i++){
       (*returnColumnSizes)[i] = 3;
    }

    return res;

}

int compare(const void* a , const void *b){
    return *((int*)a) - *((int*)b);
}
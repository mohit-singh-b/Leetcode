int pivotIndex(int* nums, int numsSize) {

    int i, sum = 0;

    int *s = calloc(numsSize , sizeof(int));

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
        s[i] = sum;
    }
    if ( numsSize == 1)
        return 0;

    for (i = 0; i < numsSize-1; i++) {
        
        if ( i == 0 && s[i] == s[numsSize -1 ])
            return 0;
        if (s[i] + s[i + 1] == s[numsSize - 1]) {
            return i + 1;
        }

    }
    return -1;
}
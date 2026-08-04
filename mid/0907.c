int sumSubarrayMins(int* arr, int arrSize) {
    int i,j,k,top=-1 ;
    long long sum = 0,left ,right;
    int *stack = malloc(arrSize*sizeof(int));
    int *l = malloc(arrSize*sizeof(int));

    for ( i = 0 ; i < arrSize ; i++){


        while ( top != -1 && arr[i] < arr[stack[top]]){
            left = stack[top] - l[stack[top]] + 1;//i - j +1 
            right = i-1 - stack[top] + 1;
            
            sum += left*right*arr[stack[top]];
            top--;
        }

        if (top != -1 ) 
            {   l[i] = stack[top]+1;
            stack[++top] = i;}
        else {
            l[i] = 0;
            stack[++top] = i;
        }


    }

      while ( top != -1 ){
            left = stack[top] - l[stack[top]] + 1;//i - j +1 
            right = arrSize -1  - stack[top] + 1; // k - i+1
            sum += left*right*arr[stack[top]];
            top--;
        }
        free(l);
        free(stack);
    return sum%1000000007;

}
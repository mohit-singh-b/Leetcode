#include <stdio.h>
int largestRectangleArea(int* heights, int heightsSize) {
    int top = -1 , left , right , max = 0 , area = 0 , topi  ;
    int *stack = calloc(heightsSize , sizeof(int));
    
    for ( right = 0 ; right < heightsSize ; right++){
      
        if( top == -1){
            stack[++top] = right;
            continue;
        }
         
        while(top != -1 && heights[right] < heights[stack[top]]){
            topi = stack[top--];
            if ( top == -1)
                left = -1 ;
            else 
                left = stack[top];
            area = heights[topi]*(right - left-1);

            max = max < area ? area : max;
        }

        stack[++top] = right;
    }


    while ( top != -1){
         topi = stack[top--];
            if ( top == -1)
                left = -1 ;
            else 
                left = stack[top];

            area = heights[topi]*(right - left-1);

            max = max < area ? area : max;
    }

    return max ;
}
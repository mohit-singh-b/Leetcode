/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int quicksort(int **,int,int,int);
 
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
     int i , n = intervalsSize,start,end,pstart,pend,n2=1;
    int **p = calloc(n,sizeof(int*));

    
    *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = 2;
    }
   

    for ( i = 0 ; i < n ; i++)
            p[i] = calloc(2,sizeof(int));

    
    quicksort(intervals,n,0,n-1);

    pstart = intervals[0][0];
    pend = intervals[0][1];

    p[0][0]= pstart;
    p[0][1]=pend;

    for ( i = 1 ; i < n ; i ++)
    {
        start = intervals[i][0];
        end = intervals[i][1];
        if ( start <= pend){
            if ( pend > end)
                p[n2-1][1] = pend;
            else 
                p[n2-1][1] = end;
        }
        else {
            p[n2][0]=start;
            p[n2][1] = end;
            n2++;
        
        }

        pstart = p[n2-1][0];
        pend = p[n2-1][1];
    }
    
    *returnSize =n2;
    return p;

}

int quicksort(int **p , int n , int l , int u){

    if ( l>=u)
        return 0;
    
    int j = l , i = l-1 ;
    int *temp;

 
    while( j < u){
        if (p[j][0] > p[u][0])
            j++;
        else {
            i++;
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
            j++;
        }
    }

    temp = p[i+1];
    p[i+1] = p[u];
    p[u] = temp;



    return quicksort(p,n,l,i) + quicksort(p,n,i+2,u);
}
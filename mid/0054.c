/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

int m , n ;
m = matrixSize ;
n = *matrixColSize;

*returnSize = m*n ;
int *b = malloc(m*n*sizeof(int));

int i = 0 , j = 0 , c=0, a=0 , N , M = m-1;

for ( N = n-1 ; N >= 0 && M>=0; N-=2 , M-=2){
    i = 0 ; j = 0 ;
   
    while (1){
        b[c++] = matrix[i+a][j+a];   
        if (c > m*n-1) 
            break;

        if ( i == 0 )
            j < N ? j ++ : i++ ;
        else if ( j == N)
            i < M ? i++ : j-- ; 
        else if ( i == M )
            j > 0 ? j-- : i-- ;
        else if ( j == 0 )
            if (i > 1) 
                i--;
            else 
                break;
    } a++;
    }

return b;
}

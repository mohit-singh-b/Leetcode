/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    const int m[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    int **queue = malloc(imageSize*(*imageColSize)*sizeof(int*));
    int head = 0 , tail = 0,i ,j,val;
    for ( i = 0 ; i <  imageSize*(*imageColSize) ; i++){
        queue[i] = malloc(2*sizeof(int));
    }
    queue[tail][0] = sr;
    queue[tail++][1] = sc;
    val = image[sr][sc];
    image[sr][sc] = color;
    while( head != tail){
        i = queue[head][0];
        j = queue[head++][1];

        for ( int count = 0 ; count < 4 ; count++){
            int a = m[count][0];
            int b = m[count][1];

            if ( i+a >= imageSize || j+b >= *imageColSize || i+a < 0 || j+b < 0)
                continue;
            
            if( image[i+a][j+b] == val && image[i+a][j+b] != color){
                queue[tail][0] = i+a;
                queue[tail++][1] = j+b;

                image[i+a][j+b] = color;
            }
        }
    }
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;

}
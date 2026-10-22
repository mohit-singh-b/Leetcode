/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    bool map[200][200] = {0};
    int m[4][2] = { {0,1} , {0,-1} , {1,0} , {-1,0} };
    bool p[200*200] = {0};
    int  **res = malloc(heightsSize*(*heightsColSize)*sizeof(int*));
    int tail = 0 , head = 0 , size = 0, i , j ,r=0;
    int a,b;
    int queue[200*(200)][2];


    if ( heightsSize == 0 && *heightsColSize == 0){
        *returnSize = 0 ;
        return (int **)res;
    }

    for ( i = 0 ; i < heightsSize ; i++ ){
        queue[tail][0] = i;
        queue[tail++][1] = 0;  
        map[i][0] = true;
        p[i * (*heightsColSize) + 0] = true;
    }

    for ( i = 1 ; i < *heightsColSize ; i++){
        queue[tail][0] = 0;
        queue[tail++][1] = i;
        map[0][i] = true;
        p[0 * (*heightsColSize) + i] = true;
    }

    i = 0 ; j = 0;
    while (head < tail){

    
        i = queue[head][0];
        j = queue[head++][1];

        for ( int k = 0 ; k < 4 ; k++){
            a = m[k][0];
            b = m[k][1];

            if ( i+a >= 0 && j+b >= 0 && i+a < heightsSize && j+b < *heightsColSize &&map[i+a][j+b] == false && heights[i+a][j+b] >= heights[i][j]){
            
                queue[tail][0] = i+a;
                queue[tail++][1] = j+b;
                p[(i+a)*(*heightsColSize) + j+b] = true;
                map[i+a][j+b] = true;
                
            }
        }
        
    
    }

    head = 0 , tail = 0 ; 
    bool map2[200][200] = {0};

    for ( i = 0 ; i < heightsSize ; i++ ){
        queue[tail][0] = i;
        queue[tail++][1] = *heightsColSize-1;  
        map2[i][*heightsColSize-1] = true;

        if ( p[(i)*(*heightsColSize) + *heightsColSize-1] ){
            res[r] = malloc(2*sizeof(int));
            res[r][0] = i;
            res[r++][1] = *heightsColSize-1;
        }
    }

    for ( i = 0 ; i < *heightsColSize-1 ; i++){
        queue[tail][0] = heightsSize-1;
        queue[tail++][1] = i;
        map2[heightsSize-1][i] = true;

        if ( p[(heightsSize-1)*(*heightsColSize) + i] ){
            res[r] = malloc(2*sizeof(int));
            res[r][0] = heightsSize-1;
            res[r++][1] = i;
        }
    }

    i = 0 ; j = 0;

    while (head < tail){

        
        i = queue[head][0];
        j = queue[head++][1];

        for ( int k = 0 ; k < 4 ; k++){
            a = m[k][0];
            b = m[k][1];

            if ( i+a >= 0 && j+b >= 0 && i+a < heightsSize && j+b < *heightsColSize &&map2[i+a][j+b] == false && heights[i+a][j+b] >= heights[i][j]){
            
                queue[tail][0] = i+a;
                queue[tail++][1] = j+b;
                map2[i+a][j+b] = true;
                if(p[(i+a)*(*heightsColSize) + j+b]){
                    res[r] = malloc(2*sizeof(int));
                    res[r][0] = i+a;
                    res[r++][1] = j+b;
                }
                
            }
        }
            
        
    }
    *returnColumnSizes = malloc(r*sizeof(int));
    for ( i = 0 ; i < r ; i++){
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = i;
    return res;


    
}
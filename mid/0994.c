

int orangesRotting(int** grid, int gridSize, int* gridColSize) {

    int size = gridSize*gridColSize[0]*2,time = 0,i=0,j=0,head=0,tail=0;
    int a,b;

   
    const int m[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int **queue = calloc(size,sizeof(int*));
  
    for ( i = 0 ; i < size ; i++){
        queue[i] = calloc(2,sizeof(int));
    }


    for ( i = 0 ; i < gridSize ; i++){
        for(j=0 ; j < gridColSize[0] ; j++){
            if ( grid[i][j] == 2){
                queue[tail][0] = i;
                queue[tail++][1] = j;
            }
        }
    }

    queue[tail++] = NULL;

    while ( head != tail ){
        if ( queue[head] == NULL && queue[tail-1]== NULL){
            break;
        }
        if ( queue[head] == NULL){
            head++;
            time++;
            queue[tail++] = NULL;
            continue;
        }

        i = queue[head][0];
        j = queue[head++][1];

        for ( int k = 0 ; k < 4 ; k++ ){
            a = m[k][0];
            b = m[k][1];
            if ( i+a >= 0 && j+b >= 0 && i+a < gridSize && j+b < gridColSize[0]  && grid[i+a][j+b] == 1){
              
                grid[i+a][j+b] = 2;
                queue[tail][0] = i+a;
                queue[tail++][1] = j+b;
            }
        }


    }

    for ( i = 0 ; i < gridSize ; i++){
        for(j=0 ; j < gridColSize[0] ; j++){
            if ( grid[i][j] == 1){
                return -1;                
            }
        }
    }
   

    return time;
}
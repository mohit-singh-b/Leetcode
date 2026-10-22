int numIslands(char** grid, int gridSize, int* gridColSize) {
    int queue[gridSize*(*gridColSize)][2];
    int i,j,a,b,m,n,island=0;
    int head = 0 , tail = 0 ;
    const int map[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    for ( m = 0 ; m < gridSize ; m++){
        for ( n = 0;  n < *gridColSize ; n++){

            if ( grid[m][n] == '0')
                continue;

            queue[tail][0] = m;
            queue[tail++][1] = n;
            grid[m][n] = '0';

            while ( head != tail ){
                i= queue[head][0];
                j = queue[head++][1];

                for ( int count = 0 ; count < 4 ; count++){
                    a = map[count][0];
                    b = map[count][1];

                    if ( i+a < 0 || j+b < 0 || i+a >= gridSize || j+b >= *gridColSize )
                        continue;
                    if(grid[i+a][j+b] != '0'){
                        queue[tail][0] = i+a;
                        queue[tail++][1] = j+b;
                        grid[i+a][j+b] = '0';
                    }
                }
            }
            island++;
        }}

        return island;    
}
int findCircleNum(int** m, int n, int* isConnectedColSize) {
    int *queue , head = 0 , tail = 0 ,provinces = 0,i;
    bool *map;
    int pop;

    queue = malloc(n*sizeof(int));
    map = calloc(n,sizeof(bool));
    
    for ( int city = 0 ; city < n ; city ++){
        if ( map[city] == true )
            continue;
    

        queue[tail++] = city;
        map[city] = true;
        while ( head != tail){
            pop = queue[head++];
            for ( i = city+1 ; i < n ; i++){

                if ( m[pop][i]  == true && map[i] == false ){
                    
                    queue[tail++] = i;
                    map[i] = true;
                }
            }
        }
        provinces++;
    }
    free(map);
    free(queue);

    return provinces;
}
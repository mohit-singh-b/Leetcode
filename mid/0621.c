int comp( const void *a , const void *b);
int leastInterval(char* tasks, int tasksSize, int n) {
    int i , j , k , cycles = 0 , n2 = n+1,tt=tasksSize,num,c;
    int map[26] = {0};

    for ( i = 0 ; i < tasksSize  ;i++)
        map[(char)tasks[i] - 'A'] ++;

    if ( n == 0 )
        return tt;
    qsort(map,26,sizeof(int),comp);
    while ( tt > 0){
        n2 = n+1;
        for ( i = 0 ; n2 > 0 && i < 26 ; i++){
            if ( map[i] == 0)
                break;
            map[i]--;
            n2--;    
            tt--;      
        }
        
        cycles++;

        if (n2 != 0)
            continue;
            
        i--;
        k = i ; j = i;num = map[i];
        
        while(k-1 >=0 && map[k-1] == map[k])
            k--;
        while(j+1 < 26 && map[j+1] == num+1)
            j++;

        if ( j != i){

            for (c = k ; c-k < j-i ; c++ ){
                map[c] = num+1;
            }
            for (; c <= j ; c++)
                map[c] = num;
        }
       
      
    }
    
    return cycles*(n+1) - n2;
    
}

int comp( const void *b , const void *a){
    return *((int*) a) - *((int *)b);
}
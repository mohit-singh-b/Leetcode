int openLock(char** deadends, int deadendsSize, char* target) {
    bool s1[10000] = {0};
    int q1[10000];
    int h1 = 0 , h2 = 0 , t1 = 0 , t2 = 0 ,lvl=0;
    int d , num ,p,n,size = 0;


    for ( int i = 0 ; i < deadendsSize ; i++){
        if ( atoi(deadends[i]) == 0)
            return -1;
        s1[atoi(deadends[i])] = true;}

    q1[(t1++)%10000] = 0;
    s1[0] = true;
    q1[(t1++%10000)] = -1;
    size+=2;

    while ( 1){
        if ( q1[(h1%10000)] == -1 && q1[(t1-1)%10000] == -1){
            return -1;
        }

        if ( q1[(h1)%10000] == -1){
            h1++;
            size--;
            q1[(t1++)%10000] = -1;
            lvl++;
            continue;
        }

        num = q1[(h1++)%10000];
        if ( num == atoi(target))
            return lvl;
        
        size--;

        for ( int i = 1 ; i < 1001 ; i*=10){
            p =  ((num/i)%10 == 9) ? num-9*i :  num+i;
            n =  ( (num/i)%10 == 0 ) ? num + 9*i :  num - i; 

            

            if ( s1[p] == false){
                q1[(t1++)%10000] = p;
                size++;
                s1[p] = true;
            }
            if(s1[n] == false ){
                q1[(t1++)%10000] = n;
                size++;
                s1[n] = true;
            }
        }      
    }
       
    

}
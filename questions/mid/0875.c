bool willdo(int * , int ,int,int);
int minEatingSpeed(int* piles, int pilesSize, int h) {
    long long l=piles[0],u=piles[0],mid;

    for ( int i = 0 ; i < pilesSize ; i++){
        l = l <= piles[i] ? l : piles[i];
        u = u >= piles[i]? u : piles[i];
    }
   
    l= pilesSize*l/h  ;
    u=((pilesSize)+h-1)*u/h;
    l = l > 0 ? l : 1;

    printf("(%d,%d)",l,u);
    while( l < u){
        mid = (l+u)/2;
      
        if ( willdo(piles,pilesSize,h,mid)){
            u=mid;
        }
        else {
            if(l==mid)return u;
            l = mid;
        }
    }

    return u;
}

bool willdo(int* piles, int pilesSize, int h , int k){
    long long totaltime = 0 ; 
    for ( int i = 0 ; i < pilesSize ; i++){
        totaltime+= 1 + (piles[i] -1)/k;
    }
    
    return totaltime <= h;
}
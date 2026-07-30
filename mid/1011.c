bool willdo(int *weights,int weightsSize,int days,int minsize);

int shipWithinDays(int* weights, int weightsSize, int days) {
    int l , u , mid, d , sum=0,max = weights[0] ;

    
    for ( int i = 0 ; i < weightsSize ; i++){
        sum+=weights[i];
        max = max > weights[i] ? max : weights[i];
    }

    l = max;
    u = sum;
    sum = 0;
    
    while ( u > l){
        mid = (u+l)/2;
        if (willdo(weights,weightsSize,days,mid)){
            u = mid;
        }
        else{
            if ( l== mid)
                break;
            l=mid;
        }
    }


    if (willdo(weights,weightsSize,days,l))
        return l;
    else 
        return u;
}

bool willdo(int *weights,int weightsSize,int days,int minsize){
    int sum =0,d=1;
    for( int i = 0 ; i < weightsSize ; i++){
        sum+=weights[i];
        if( sum > minsize ){
            d++;
            sum = weights[i];
        }
    }

    return d >  days ? false : true;
}
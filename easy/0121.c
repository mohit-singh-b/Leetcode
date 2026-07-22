int maxProfit(int* prices, int pricesSize) {
    int min = prices[0] , i , maxp = 0 ;

    for ( i = 0 ; i< pricesSize ; i++)
    {
        if( prices[i] < min)
            min = prices[i];
        int profit = prices[i] - min;
        if ( profit > maxp)
            maxp = profit ;
    }

    if ( maxp > 0)
        return maxp;
    else 
        return 0;
}
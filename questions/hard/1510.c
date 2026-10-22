bool winnerSquareGame(int n) {
    int i , j , sqr ;
    bool flag = false;
    bool *dp = malloc((n+1)*sizeof(bool));
    dp[0] = false;

    for ( i = 1 ; i <= n  ; i ++){
        flag = false;
        for ( j = 1 ; j <= sqrt(i) ; j++ ){
            sqr= j*j;
            
            if ( dp[i - sqr] == false )
                flag = true;

        }
        dp[i] = flag;
        
    }
    
    return dp[n];
}
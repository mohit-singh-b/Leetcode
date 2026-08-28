class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        for ( int e: piles)sum+=e;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for ( int i = n-1 ; i >= 0 ; i--){
            for ( int m = n ; m> 0 ; m--){
                int cs = 0 ,best = INT_MIN;

                for ( int x = 1 ; x <= min(2*m, n-i) ; x++){
                    cs+=piles[i+x-1];
                    best = max(best,cs-dp[i+x][max(m,x)]);
                }
                dp[i][m] = best;
            }
        }

        return (dp[0][1]+sum)/2;
    }
};
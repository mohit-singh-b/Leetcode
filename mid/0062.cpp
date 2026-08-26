vector<vector<int>> dp(100,vector<int>(100,1));
class Solution {
public:
    int uniquePaths(int m, int n) {

        if ( dp[m-1][n-1] != 1 && !(m-1) && !(n-1)) return dp[m-1][n-1];
        a
        for ( int i = 1 ; i < m ; i++){
            for ( int j = 1 ; j < n ; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }

        return dp[m-1][n-1];
    }
};
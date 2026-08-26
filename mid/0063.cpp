class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<double>> dp(m,vector<double>(n,1));

       
        for ( int i = 0 ; i < m ; i++){
            for ( int j = 0 ; j < n ; j++){

                if ( obstacleGrid[i][j] ){ dp[i][j] = 0;continue;}
                if( !i && !j){ dp[0][0] = 1; continue;}
                if (!i) {dp[0][j] = dp[i][j-1];continue;}
                if (!j) {dp[i][0] = dp[i-1][j];continue;}

                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }}

        return dp[m-1][n-1];
    }
};
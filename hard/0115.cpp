class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        dp[0][0] = 1;
        for ( int i = 0 ; i < m+1; i++){
            for ( int j = 1 ; j < n+1 ; j++){
                if (!i){dp[0][j] = 1;continue;}

                if ( t[i-1] == s[j-1] && dp[i][j-1] <= INT_MAX- dp[i-1][j-1]  ) 
                    dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
                else
                     dp[i][j] = dp[i][j-1];

            }
        }

        return dp[m][n];
    }
};
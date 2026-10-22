class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));

        dp[0][0] = true;
        for ( int i = 0 ; i < m+1 ; i++) {
            for ( int j = 1 ; j < n+1 ; j++){
                if(!i && dp[0][j-1]  && m+1 >= j+1 && p[j] == '*'){
                    dp[0][j] = true;
                    dp[0][j+1] = true;
                }
                if(!i) continue;
                if( p[j-1] != '*') dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.')&& dp[i-1][j-1];
                else dp[i][j] = ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j] ) || dp[i][j-2];
                    
            }
        }


        return dp[m][n];
    }
};
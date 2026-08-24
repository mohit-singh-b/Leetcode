class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,0);
        
        if ( s[0] == '0')return 0;
        dp[0] = 1;
        dp[1] = 1;        

        for (int i = 1; i < n ; i++){
            int j = i+1;
            if ( s[i] != '0')
                dp[j] = dp[j-1];
            if ( s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                dp[j] += dp[j-2];

            if ( dp[j] == 0)
                return 0;
        }
        return dp.back();
    }
};
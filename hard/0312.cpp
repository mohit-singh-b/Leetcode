class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size() ;

        vector<vector<int>> dp(n,vector<int>(n,0));

        for ( int len = 3 ; len <= n ; len++){
            for ( int l = 0 ; l+len-1 < n ; l++ ){
                int r = l+len-1;
                for( int k = l+1 ; k < r ; k++){
                    dp[l][r] =max(dp[l][r], nums[l]*nums[k]*nums[r] + dp[l][k] + dp[k][r]);
                }                
            }
        }

        return dp[0][n-1];
    }
};
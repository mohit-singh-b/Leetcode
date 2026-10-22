class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sm = 0;
        for ( int e : nums)sm+=e;
        int sumtarget = (sm-target)/2;
        if ( abs(target) > sm || (sm - target) % 2 != 0)return 0 ;
        vector<vector<int>> dp(n+1,vector<int>(sumtarget+1,0));

        dp[0][0] = 1;
        for ( int i = 1 ; i < n+1 ; i++){
            for ( int j = 0 ; j < sumtarget+1; j++){

                dp[i][j] = dp[i-1][j] ;
                if ( j-nums[i-1] >= 0 ) dp[i][j] += dp[i-1][j-nums[i-1]];
            }
        }
        

        return dp[n][sumtarget];
    }
};
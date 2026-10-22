class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(target+1,0);
        dp[0] = 1;
        for ( int i = 1 ; i < target+1 ; i++){
           
           for ( auto& e : nums){
            if ( i-e >= 0&& dp[i] <= INT_MAX -dp[i-e])
                dp[i] += dp[i-e];
           }
        }

        return dp[target];
    }
};
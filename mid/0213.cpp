class Solution {
public:
    int rob(vector<int>& nums) {
        int  n = nums.size();
        vector<int> dp1(n,0),dp2(n,0);
        dp1[0] = nums[0];
        dp2[0]=0;
        int mx1=0,mx2=0;

        if ( n == 1)return nums[0];
        for ( int i = 1; i < n ; i++){
            dp1[i] = nums[i] + mx1;
            dp2[i] = nums[i] + mx2;
            mx1 = max(dp1[i-1],mx1);
            mx2 = max(dp2[i-1],mx2);

        }
        mx2 = max(dp2[n-1],mx2);


        return max(mx1,mx2);        
    }

};
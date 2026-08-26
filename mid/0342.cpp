int N = 58;
vector<int> dp(N+1,0);
class Solution {
public:
    int integerBreak(int n) {
        static bool ran = false;
        if ( !ran){
            ran = true;
            res(N);
        }

        if ( n == 2)return 1;
        if ( n== 3) return 2;

        return dp[n];
    }

    void res(int n){
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i < n+1 ; i++){
                dp[i] = max(dp[i/2]*dp[i-(i/2)] , dp[i/2-1]*dp[i-(i/2)+1]);
        }
    }
};
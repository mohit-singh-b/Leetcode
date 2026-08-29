class Solution {
public:
    int jump(vector<int>& nums) {
        int reach  = 0,step = 0 , max_reach = 0;
        int n = nums.size();
       
        for ( int i = 0 ; i <= min(reach,n-1) ; i++){
            max_reach = max(max_reach,nums[i]+i);
            if ( i!=n-1 &&  i == reach){
                reach = max_reach ;
                step++;
            }
        }
        return step;

    }
};
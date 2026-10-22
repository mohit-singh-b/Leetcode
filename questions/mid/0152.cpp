class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 1 , mnn= 1, globalmax = nums[0] ; 

        for ( auto & e : nums){

            if ( e < 0){
                double temp = mx;
                mx = mnn;
                mnn = temp;

            }

            mx = max(e , mx*e);
            mnn = min(e,mnn*e);
            globalmax = max(mx,globalmax);
        }

        return globalmax;
    }
};
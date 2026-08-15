class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =0 , u = nums.size()-1 ,mid , e = nums[0];

        while ( l < u ){    
                mid = l + (u-l)/2;
            if ( nums[mid] >= e)
                l = mid+1;
            else 
                u= mid;
            
        }

        return min(e,nums[u]);
    }
};
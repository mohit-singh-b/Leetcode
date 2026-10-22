class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid , l = 0 , u = nums.size()-1 ;
        int a , b;
        if ( nums.empty())
            return {-1,-1};

        if ( nums.size() == 1){
            if ( nums[0] == target )
                return {0,0};
            else 
                return {-1,-1};
        }

        while ( l < u ){
            mid = l + (u-l+1)/2;
            if ( nums[mid] < target)
                l = mid;
            else 
                u = mid-1;         
        }

        int lower = nums[l] != target ? l+1 : l;
        
        l = 0 , u = nums.size()-1 ;
        
        while ( l < u ){
            mid = l + (u-l)/2;
            if ( nums[mid] > target)
                u = mid;
            else 
                l = mid+1;         
        }
        int upper = nums[l] != target ? l-1 : l;
        
        if ( lower > upper)
            return {-1,-1};

        return {lower,upper};
    }
};
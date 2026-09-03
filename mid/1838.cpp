class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long cs = 0,j=0,res=1;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for (int i = 1 ; i < n ; i++){
            cs+=1LL*(i-j)*(nums[i]-nums[i-1]);
            if(j< i && cs>k){
                cs-=nums[i]-nums[j];
                j++;
            }
            res= i-j+1;
        }

        return res;
    }
};
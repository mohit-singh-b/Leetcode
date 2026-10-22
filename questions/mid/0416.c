class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 , target, i ;

        for ( int &e : nums){
            sum+=e;
        }
        if ( sum %2 == 1)
            return false ;
        else 
            target = sum/2;

        vector <bool> h(target,false);
        vector<int> a,t;
        a.emplace_back(0);

        for ( i = 0 ; i < nums.size(); i++){
            t.clear();
            for ( int& e : a){
                if ( e+nums[i] == target )
                    return true ;
                if ( e+nums[i] > target )
                    continue;
                if ( h[e+nums[i]] == false){
                t.emplace_back(e+nums[i]);
                h[e+nums[i]] = true;}
            }
            a.insert(a.end(),t.begin(),t.end());
        }
        return false;
    }
};
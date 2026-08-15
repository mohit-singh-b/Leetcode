class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0, prevst;

        sort(intervals.begin(),intervals.end(),comp);
        prevst = intervals[0][0];
        for ( auto it = intervals.begin() +1; it != intervals.end() ; it++){
            vector<int>& pair = *it;
            if ( pair[1] > prevst)
                res++;
            else 
                prevst = pair[0];
        }

        return res;
    }

    static bool comp(const vector<int>& a , const vector<int>& b){
        if (a[0] > b[0])return true;
        return false;
    }

};
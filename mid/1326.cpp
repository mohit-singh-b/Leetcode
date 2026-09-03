class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        stack <pair<int,int>> st;
        
        for ( int i = 0 ; i < n+1 ; i++){
            int  l = i-ranges[i];
            int r = i+ranges[i];
           
            while(!st.empty() && l <= st.top().first && r > st.top().second ){
                st.pop();
            }
            if(st.empty()) {
                st.push({0,r});
                continue;
            }
            
            if ( l <= st.top().second && r > st.top().second && st.top().second < n)
                st.push({st.top().second,r});
            
        }

        if ( st.top().second < n)return -1;
        return st.size();

        
    }
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = 1, max_len = 1;
        int n = arr.size();
        int prev = INT_MAX ;

        if ( n == 2)
            return arr[0] != arr[1] ? 2 : 1 ;

        for ( int i = 1 ; i < n ; i++){
            if ( prev == INT_MAX ) prev = arr[0]-arr[1];
            int curr = arr[i]-arr[i-1];
            
            curr = (curr > 0 ) - (curr < 0);
              prev = (prev> 0 ) - (prev < 0);

            if ( curr*prev < 0 ) 
                len++;
            else if ( curr == 0 )
                len= 1;
            else 
                len = 2;

            prev  = curr;
            max_len = max(max_len,len);
            
        }

        return max_len;
    }
};
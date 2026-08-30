class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total =0;
        int cs =0 ,index = -1;

        for ( int i = 0  ; i < n; i++){
            gas[i] -=cost[i];

            cs+=gas[i];
            total += gas[i];

            if (  cs < 0 ){
                cs = 0 ;
                index = -1;
            }
            else if ( index == -1) 
                index = i ;
        }

        if ( total < 0 )
            return -1;
        return index;
    }
};
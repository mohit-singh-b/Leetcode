vector<int> power(3002,0);

class Solution {
public:
    int getKth(int lo, int hi, int k) {
    
        if ( !power[2]){
            int pw =1;
            for ( int i = 2 ; i < 3002 ; i*=2)power[i]=pw++;
            for ( int i = 1 ; i <= 1000; i++){
            power[i] = calc_power(i);
            }
        }

        int n  = hi-lo+1;
        vector <int> indexes(n,0);
        for ( int i = 0 ; i < n ; i++){
            indexes[i] = i+lo;
        }


        

        sort(indexes.begin(),indexes.end(),comp);

        return indexes[k-1];

        
    }

    int calc_power(int n){
        if (n < 3002 && power[n] != 0)return power[n];
        if (( n&(n-1)) == 0) return sqrt(n);
        int pow ;
        if( n&1 ){
             pow = 1+calc_power(3*n+1);
        }else{
             pow = 1+calc_power(n/2);
        }
        if( n < 3002) power[n] = pow;
        return pow;        
    }

    static bool comp(int a , int b){
        if (power[a] < power[b])return true;
        if ( power[a] > power[b])return false;
        return a < b;
    }

};
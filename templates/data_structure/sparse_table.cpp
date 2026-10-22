#include <bits/stdc++.h>
using namespace std;

class sparse{
    vector<vector<long long>> table;
    vector<int>& nums;
    int maxj , n ;
    long long (*select)(long long , long long);
    public:
    sparse(int n ,vector<int>& nums, long long (*select)(long long , long long )) : n(n) , nums(nums), select(select) {
        int maxj = __lg(n);
        this->maxj =maxj;
        table.resize(n,vector<long long>(maxj+1,0));
    }

    void build(){   
        for ( int i = 0 ; i < n ; i++) table[i][0] = nums[i];
        for ( int j = 1 ; j <= maxj ; j++){
            for ( int i = 0 ; i+(1<<(j)) <= n ; i++){
                table[i][j] = select(table[i][j-1] ,table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    long long query(int l , int r){
        int len = r-l+1;
        int j = __lg(len);
        return select(table[l][j] ,table[r-(1<<j)+1][j]) ;
    }
    
};
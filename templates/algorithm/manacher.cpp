#include <bits/stdc++.h>
using namespace std;

class manacher{
    string t;
    vector<int> p;
    public:
    manacher(string s){
        int n = s.size();
        t = "^#";
        for ( char c : s) {t+=c;t+='#';}
        p.resize(t.size(),1);
        build(t.size());
    }

    void build(int n){
        int l = 1 , r = 1 ;
        for ( int i = 1 ; i < n ; i++){
            p[i] = max(1,min(r-i,p[l+r-i]));
            int a = i-p[i], b = i+p[i];
            while( a >= 0 && b < n && t[a] == t[b] ){
                a--;
                b++;
                p[i]++;
            }

            if ( b > r){
                r = b;
                l =a;
            }
        }
    }

    int getlen( int centre , bool is_odd){
        int new_centre = 2*centre + 1 + !is_odd;
        return p[new_centre+1]-1;
    }

    bool is_palindrome( int l , int r){
        return r-l+1 <= getlen(l+(r-l)/2,l%2==r%2);
        
    }
};
#include <bits/stdc++.h>
using namespace std;

class fenwick{
    vector<long long> bit;
    int n ;
    public:
    fenwick(int n  ) : n(n)  {
        bit.resize(n+2,0);
    }

    void add( int i , long long val){

        for (  ; i <= n+1 ; i+= (i+1)&(-i-1) ){
            bit[i] += val;
        }
    }

    long long query(int i ){
        long long res= 0;
        for ( ; i >= 0 ; i-= (i+1)&(-i-1) )
            res+=bit[i];
        return res;
    }
};

class rrfenwick{
    fenwick b1,b2;
    public : 
    rrfenwick(int n) :  b1(n) , b2(n) {}

    void add(int l , int  r, long long val){

        b1.add(l,val);
        b1.add(r+1,-val);
        b2.add(l,val*l);
        b2.add(r+1,-val*(r+1));
    }

    long long query(int i ){
        return (i+1)*b1.query(i) - b2.query(i);
    }
};
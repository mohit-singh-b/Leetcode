#include <bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> parent,size;
    public:
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for ( int i =0 ; i < n ; i++) parent[i] = i;
    }

    int root( int n){
        if ( parent[n] == n) return n;
        return parent[n] = root(parent[n]);
    }

    bool unions(int ac , int bc){
        int a = root(ac);
        int b = root(bc);
        if ( a==b) return false;
        if ( size[a] > size[b]){
            parent[b] = a;
            size[a]+=size[b]; 
        }else{
            parent[a] = b;
            size[b]+=size[a];
        }

        return true;
    }
};
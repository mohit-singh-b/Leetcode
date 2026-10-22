#include <bits/stdc++.h>
using namespace std;
class segtree{
    vector<long long> tree,lazy;
    vector<int>& nums;
    long long (*merge)(long long , long long );
    int n;
    long long initial ;
    public:
    segtree(int n , vector<int>& nums , long long (*merge)(long long , long long ) , long long initial ) : 
    nums(nums)  ,merge(merge) , n(n), initial(initial) {
        tree.resize(4*n,initial);
        lazy.resize(4*n,0);
        build(0,n-1,0);
    }

    long long build(int l , int r ,int node){
        if ( l == r ) return tree[node] = nums[l];
        int mid = l+(r-l)/2;
        long long left = build(l,mid,node*2+1);
        long long right = build(mid+1,r,node*2+2);

        return tree[node] = merge(left,right);
    }

    long long query(int l , int r, int low , int high ,  int node){
        if ( low > high) return initial;
        if ( l == low && r == high ) return tree[node];

        int mid = l+(r-l)/2;
        push(l,r,node);
        long long left = query(l,mid,low,min(high,mid),node*2+1);
        long long right = query(mid+1,r,max(mid+1,low),high,node*2+2);
        return merge(left,right);
    }

    long long point_update(int l , int r , int i , int val , int node ){
        if ( l > i || r < i ) return tree[node];
        if ( l == r) return tree[node] += val;
        int mid = l+(r-l)/2;
        push(l,r,node);
        long long left = point_update(l,mid,i,val,node*2+1);
        long long right = point_update(mid+1,r,i,val,node*2+2);
        
        return tree[node] = merge(left,right);
    }

    long long point_set(int l , int r , int i , int val , int node ){
        if ( l > i || r < i ) return tree[node];
        if ( l == r) return tree[node] = val;
        int mid = l+(r-l)/2;
        push(l,r,node);
        long long left = point_set(l,mid,i,val,node*2+1);
        long long right = point_set(mid+1,r,i,val,node*2+2);
        
        return tree[node] = merge(left,right);
    }

    long long range_update(int l , int r , int low , int high , long long val , int node){
        if ( low > high ) return tree[node];
        if ( low == l && high == r ){lazy[node] += val; return tree[node] += val*(r-l+1);}

        int mid = l+(r-l)/2;
        push(l,r,node);
        long long left = range_update(l,mid,low,min(high,mid),val,node*2+1);
        long long right = range_update(mid+1,r,max(low,mid+1),high,val,node*2+2);

        return tree[node] = merge(left,right);
    }

    void push( int l , int r , int node){
        if ( lazy[node] == 0) return ;
        long long update = lazy[node];
        lazy[node] = 0;
        if ( l == r ) return ;

        int mid = l+(r-l)/2;
        tree[node*2+1] += (mid-l+1)*update;
        tree[node*2+2] += (r-mid)*update;
        lazy[node*2+2]+=update;
        lazy[node*2+1] += update;
    }
};
class dsu{
    vector<int> parent,size;
    public : 
    dsu(int n){
        size.resize(n,1);
        parent.resize(n);
        for ( int i = 0 ; i < n ; i++) parent[i] = i;
    }
    int root(int n){
        if ( parent[n] == n) return n;
        return parent[n] = root(parent[n]);
    }

    bool unions(int ac , int bc){
        int a = root(ac);
        int b = root(bc);
        if ( a == b) return false;
        if( size[a] > size[b]){
            parent[b] = a;
            size[a]+=size[b];
        }else{
            parent[a] = b;
            size[b] += size[a];
        }
        return true;
    }

    bool check(){
        int head = 0;
        for ( int i = 0 ; i < parent.size(); i++){
            if ( parent[i] == i)head++;
            if ( head > 1)return false;
        }
        return true;
    }

};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        dsu ds1(nums.size());
        unordered_map <int,int> hash;

        for ( int i = 0 ; i < nums.size() ; i++){
            int num = nums[i];
            for ( int e = 2 ; e <=sqrt(nums[i]) ; e++){
                if ( num%e )continue;
                while(num%e == 0)
                    num/=e ;
                if ( hash.contains(e)){
                    ds1.unions(hash[e],i);}
                else 
                    hash[e] = i;
            }
            if ( num != 1){
                int e = num;
                if ( hash.contains(e)){
                    ds1.unions(hash[e],i);}
                else 
                    hash[e] = i;
            }
        }

        return ds1.check();
    }
};
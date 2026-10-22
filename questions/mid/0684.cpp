class dsu {
    vector<int> size , parents;
    public:
        dsu(int n){
            size.resize(n+1,1);
            parents.resize(n+1);
            for ( int i = 0 ; i < n+1 ; i++)
                parents[i] = i;
        }

        int parent(int n){
            if( n == parents[n])
                return n;
            return parents[n] = parent(parents[n]);
        }

        bool unions(int a , int b){
            int pa = parent(a);
            int pb = parent(b);
            if ( pb == pa) return false;
            if ( size[pa] > size[pb]){
                parents[pb] = pa;
                size[pa]+=size[pb];
            }
            else {
                 parents[pa] = pb;
                size[pb]+=size[pa];
            }

            return true;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu ds((edges.size()));

        for ( auto& edge :edges){
            int a = edge[0];
            int b = edge[1];
            if ( !ds.unions(a,b))
                return {a,b};
        }
        return{-1,-1};
    }
};
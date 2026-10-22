class dsu{
    vector<int> size , parent;

    public : 
        dsu(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for ( int i = 0 ; i < n+1 ; i++){
                parent[i] = i;
            }
        }

        int root(int n){
            if ( n == parent[n])
                return n;
            return parent[n] = root(parent[n]);
        }
        bool unions(int a , int b){
            int ra = root(a);
            int rb = root(b);
            if (rb == ra) return false;
            if ( size[rb] > size[ra]){
                parent[ra] = rb;
                size[rb]+=size[ra];
            }
            else{
                parent[rb] = ra;
                size[ra]+=size[rb];
            }
            return true;
        }

        bool reach(){
            int head=0;
            for ( int i = 1 ; i < parent.size() ; i++){
                if ( parent[i] == i){
                    head++;
                    if ( head >1)
                        return false;
                }
            }
            return true;
        }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu dsu1(n),dsu2(n);
        int dlt =0,i=0;

        while ( i < edges.size() ){
            auto edge = edges[i];
            int a = edge[1];
            int b = edge[2];
            if ( edge[0] != 3){
                i++;continue;
            }
            bool dsua = dsu1.unions(a,b),dsub = dsu2.unions(a,b);

            if ( !dsua && !dsub ){
                dlt++;
                edges[i] = edges.back();
                edges.pop_back();       
            }
            else
                i++;
        }

        for ( auto& edge : edges ){
            int t = edge[0];
            int a = edge[1];
            int b = edge[2];

            if ( t == 3)
                continue;

            if (t == 1){
                if ( !dsu1.unions(a,b))
                    dlt++;
            }
            else {
                if ( !dsu2.unions(a,b))
                    dlt++;
            }
        }

        if ( (dsu1.reach())==false  || (dsu2.reach())== false)
            return -1;

        return dlt;
    }
};
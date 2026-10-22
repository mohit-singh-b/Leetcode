class dsu{
    vector <int> size , parent;
    public : 
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for ( int i = 0 ; i < n+1 ; i++)
            parent[i] = i;
    }

    int root(int n){
        if ( parent[n] == n) return n;
        return parent[n] = root(parent[n]);
    }

    bool unions(int a , int b){
        int ra = root(a);
        int rb = root(b);
        if ( ra == rb)return false;
        if ( size[ra] > size[rb]){
            parent[rb] = ra;
            size[ra]+=size[rb];
        }
        else{
            parent[ra]=rb;
            size[rb] +=size[ra];
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        dsu ds1(edges.size());
        vector <vector<int>> res(2);

        for ( int i = 0 ; i < edges.size() ; i++){
            edges[i].emplace_back(i);}

        sort(edges.begin() , edges.end() , comp);

        int mst = 0;
        int nodes = 0;
        for ( int i = 0 ;i < edges.size() ; i++){
            auto edge = edges[i];
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];
            int node = edge[3];

            if ( ds1.unions(a,b)) {
                mst+=w;
                if ( ++nodes == n)break;
            }
        }
        int minst = mst;

        for ( int j = 0 ; j < edges.size() ; j++){
            dsu ds2(edges.size());
            mst = 0;
            nodes = 0;
            int node = edges[j][3];

            for ( int i = 0 ;i < edges.size() ; i++){
                if ( i == j )continue;
                auto edge = edges[i];
                int a = edge[0];
                int b = edge[1];
                int w = edge[2];

                if ( ds2.unions(a,b)) {
                    mst+=w;
                    if ( ++nodes == n)break;
                }
            }
            if ( minst != mst){
                res[0].emplace_back(node);
                continue;
            }
            dsu ds3(edges.size());
            ds3.unions(edges[j][0],edges[j][1]);
            nodes = 1;
            mst = edges[j][2];

            for ( int i = 0 ;i < edges.size() ; i++){
                auto edge = edges[i];
                int a = edge[0];
                int b = edge[1];
                int w = edge[2];

                if ( ds3.unions(a,b)) {
                    mst+=w;
                    if ( ++nodes == n)break;
                }
            }
            if ( mst == minst){
                res[1].emplace_back(node);
            }

        }

        return res;
       
    }

    static bool comp(const vector<int>& a , const vector<int>& b){
        if ( a[2] < b[2])return true;
        return false;
    }
};
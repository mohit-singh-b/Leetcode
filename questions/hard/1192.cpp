class Solution {
    int time = 0;
    void dfs(int node, int parent , vector<vector<int>>& graph,vector<int>& it , vector<int> & mt ,vector<bool>& vis,vector<vector<int>>&res){
        vis[node] = true;
        it[node] = time;
        mt[node] = time;
        time++;

        for ( auto& n : graph[node]){
            if(n == parent)continue;
            if ( vis[n] ){
                mt[node] = min(it[n],mt[node]);
            }else{
                dfs(n,node,graph,it,mt,vis,res);
                mt[node] = min(mt[n],mt[node]);

                if ( it[node] < mt[n]){
                    res.push_back({node,n});
                }
                 
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> graph(n),res;
        vector<int> it(n) , mt(n) ;
        vector<bool> vis(n);

        for ( auto & edge : con){
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        dfs(0,-1,graph,it,mt,vis,res);
        time=0;
        return res;



    }
};
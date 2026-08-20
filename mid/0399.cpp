class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector <vector<pair<int,double>>> graph;
        unordered_map <string,int> hash;
        vector <double> res;



        for ( int i = 0 ; i < equations.size() ; i++){
            auto eq = equations[i];
            string a = eq[0];
            string b = eq[1];
            double val = values[i];
            

            if ( !hash.contains(a)){
                hash[a] = graph.size();
                graph.push_back({});
            }
            if ( !hash.contains(b)){
                hash[b] = graph.size();
                 graph.push_back({});
            }
        
            graph[hash[a]].emplace_back(hash[b],val);
            graph[hash[b]].emplace_back(hash[a],1/val);
        }

       
        

        for ( auto& query : queries){
            vector <bool> vis(graph.size());

            string a = query[0];
            string b = query[1];
            double val = -1;
            if ( hash.contains(a) && hash.contains(b)) 
             val =  dfs(graph,hash[a],hash[b],1,vis) ;
            res.emplace_back(val);
        }
        return res;
    }

    double dfs(vector<vector<pair<int,double>>>& graph , int node , const int target , double res,vector<bool>& vis){
        vis[node] = true;

        
        if ( node == target){
            return res;
        }        

        for ( auto& edge : graph[node]){
            int n = edge.first;
            double w = edge.second;
            if ( vis[n])continue;
            double val = dfs(graph,n,target,res*w,vis);
            if ( val != -1)return val;
        }

        return -1;
    }
};
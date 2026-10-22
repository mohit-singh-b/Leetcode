class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         int total = tickets.size();
        unordered_map <string,int> hash;
        vector<vector<string>> graph;
        vector <string> path ,res;

        for ( auto& ticket : tickets ){
            string a = ticket[0];
            string b = ticket[1];

            if ( !hash.contains(a)){
                hash[a] = graph.size();
                graph.push_back({});
            }
            if ( !hash.contains(b)){
                hash[b] = graph.size();
                graph.push_back({});
            }

            graph[hash[a]].emplace_back(b);
        }
       

       for ( int i = 0 ; i < graph.size() ; i++){
        sort(graph[i].begin(),graph[i].end(),greater<string>());
       }

        dfs(graph,path,hash,"JFK");
        reverse(path.begin(),path.end());
        return path;

    }

    void dfs(  vector<vector<string>>& graph , vector<string>& path ,unordered_map <string,int> &hash, string node ){
        int index = hash[node];
        while(!graph[index].empty()){
            string n = graph[index].back();
            graph[index].pop_back();
            dfs(graph,path,hash,n);
        }
        path.emplace_back(node);

    }
};
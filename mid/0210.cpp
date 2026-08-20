class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector <int> depend(n,0);
        vector <int> res;
        vector <vector<int>> graph(n);
        queue <int> q;

        for ( auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            graph[b].emplace_back(a);
            depend[a]++;
        }

        for ( int i = 0 ; i < n ;i++){
            if (depend[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.emplace_back(node);
            for ( int neb : graph[node]){
                depend[neb]--;
                if ( depend[neb] == 0 )
                    q.push(neb);
            }
        }

        for ( int e : depend){
            if ( e != 0)
                return {};
        }
        return res;


    }
};
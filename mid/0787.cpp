class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <int> dist(n,INT_MAX);
        vector <vector<pair<int,int>>> graph(n);
        queue <pair<int,int>> q;

        for ( auto& e : flights){
            graph[e[0]].emplace_back(e[1],e[2]);
        }

        q.push({src,0});
        dist[src] = 0;
        k++;
        while(!q.empty() && k ){
            int size = q.size();
            for ( int count = 0 ; count < size ; count++){
                pair<int,int> popped = q.front();
                q.pop();
                
                if ( popped.first == dst )
                    continue;
            
                for ( auto& pair : graph[popped.first]){
                    int n = pair.first;
                    int w = pair.second;

                    if ( dist[n] > popped.second + w){
                        dist[n] = popped.second + w;
                        q.push({n,dist[n]});
                    }
                }
            }
            k--;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
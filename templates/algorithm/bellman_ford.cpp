#include <bits/stdc++.h>
using namespace std;

class bellman_ford{
    int n , start ,dest;
    vector<vector<array<int,2>>>& graph;
    vector<int> dist;
    public:
    bellman_ford(int n , vector<vector<array<int,2>>>& graph) : n(n)  , graph(graph) {
       
    }

    void run(int start , int dest){
        queue <int> q;
        vector<bool> inqueue(n,false);
        dist.assign(n,1e9);

        dist[start] =0;
        q.push(start);
        inqueue[start] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            inqueue[node] = false;

            for ( auto&  nebor : graph[node]){
                int n = nebor[0];
                int w = nebor[1];
                if ( w+dist[node] < dist[n]){
                    dist[n] = dist[node] + w;
                    if ( inqueue[n]) continue;
                    inqueue[n] = true;
                    q.push(n);
                }
            }
        }
    }

    int get_distance(int node){return dist[node];}
};
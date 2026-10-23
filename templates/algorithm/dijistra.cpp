#include <bits/stdc++.h>
using namespace std;

class dijistra{
    int n ;
    vector<vector<array<int,2>>>& graph;
    vector<int> dist;
    public: 
    dijistra(int n , vector<vector<array<int,2>>>& graph) : n(n) , graph(graph)  {
        dist.resize(n,1e9);
    }

    void run(int start , int dest ){
        dist.assign(n,1e9);
        priority_queue < array<int,2> , vector< array<int,2>> , greater< array<int,2>> > pq;

        dist[start] =  0;
        pq.push({0,start});
    
        while ( !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top[1];
            int d = top[0];
            
            if (node == dest) return ;
            if ( dist[node] < d) continue;
            for ( auto&  nebor : graph[node]){
                int n = nebor[0];
                int w = nebor[1]; 
                if ( dist[n] > w+d ){
                    dist[n] = w+d;
                    pq.push({dist[n],n});
                }
            }
        }
    }

    int get_distance(int node) { return dist[node];}

};
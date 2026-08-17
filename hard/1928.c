class Solution {
public:
    int minCost(int maxtime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        priority_queue <array<int, 3> ,vector <array<int ,3>> , greater<array<int, 3>>  > pq;
        vector<int> cost(n*(maxtime+1), INT_MAX);
        vector < vector<pair<int,int>>> graph(n);

        for ( auto& edge : edges){
            int st = edge[0];
            int end = edge[1];
            int t = edge[2];
            graph[st].emplace_back(end,t);
            graph[end].emplace_back(st,t);
        }
       

        pq.push({fees[0],0,0});
        cost[0] = fees[0];

        while(!pq.empty()){
            auto popped = pq.top();
            pq.pop();
            int i = popped[2];
            int cst = popped[0];
            int time = popped[1];

            if(time >= maxtime ||  cst > cost[i*(maxtime+1)+time]   )
                continue;
            if( i == n-1)
                break;
                
            for ( auto [end,t] : graph[i] ){

                if ( time+t <= maxtime && cost[end*(maxtime+1)+time+t] > cst+fees[end] ){
                    cost[end*(maxtime+1)+time+t] = cst+fees[end];
                    pq.push({cost[end*(maxtime+1)+time+t],time+t,end});
                }
            }
        }
        int mincost = INT_MAX;
        for (int i = 0 ; i < maxtime+1 ; i++) {
            int c = cost[(n-1)*(maxtime+1)+i];
            mincost = c < mincost ? c : mincost;
        }

        return mincost != INT_MAX ? mincost : -1;
    }
};
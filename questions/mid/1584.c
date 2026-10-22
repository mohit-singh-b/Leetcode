class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue <pair<int,int> , vector <pair<int,int>> , greater<pair<int,int>> > pq;
        vector <bool> vis(points.size(),false);

        pq.push({0,0});
        int cost = 0;
        int node = 0;

        while( !pq.empty()){
            pair<int,int> popped = pq.top();
            pq.pop();
            int w = popped.first;
            int i = popped.second;
            if ( vis[i])continue;

            cost+=w;
            vis[i] = true;

            if ( ++node == points.size())break;

            for ( int j = 0 ; j < points.size() ; j++){
                if ( vis[j])continue;
                pq.push({dist(i,j,points),j});
            }

        }
        return cost;
    }

    int dist(int i , int j , vector<vector<int>>& points){
        int x = points[i][0];
        int y = points[i][1];
        int a = points[j][0];
        int b = points[j][1];
        return abs(x-a) + abs(y-b);
    }

};
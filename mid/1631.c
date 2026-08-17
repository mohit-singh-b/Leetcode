class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m[4][2] = {0,1,0,-1,1,0,-1,0};
        priority_queue < pair<int,pair<int,int> > , vector <pair<int,pair<int,int> >> , greater <pair<int,pair<int,int> >> >  pq;
        vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(),INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto popped = pq.top();
            pq.pop();

            int i = popped.second.first;
            int j = popped.second.second;
            int besth = popped.first;

            if ( dist[i][j] < besth)
                continue;
            for ( int k = 0 ; k < 4 ; k++){
                int a = i + m[k][0];
                int b = j+ m[k][1];

                if ( a < 0 || b < 0 || a >= heights.size() || b >= heights[0].size() )
                    continue;
                if ( dist[a][b] > max(besth , abs(heights[i][j] - heights[a][b]) ) ){
                    dist[a][b] = max(besth , abs(heights[i][j] - heights[a][b]) );
                    pq.push({dist[a][b] , {a,b}});
                }
            }
        }

        return dist[heights.size()-1][heights[0].size()-1];
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m[4][2] = {1,0,-1,0,0,1,0,-1};
        priority_queue < pair<int,pair<int,int>> , vector <pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq ;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            auto popped = pq.top();
            pq.pop();
            int i = popped.second.first;
            int j = popped.second.second;
            int bestt = popped.first;

            if(dist[i][j] < bestt )continue;
            for ( int k = 0 ; k < 4 ; k++){
                int a = i+m[k][0];
                int b = j +m[k][1];

                if(a < 0 || b < 0 || a>= n || b>= n ){continue;}
                if ( dist[a][b] > max(bestt,grid[a][b])){
                    dist[a][b] = max(bestt,grid[a][b]);
                    pq.push({max(bestt,grid[a][b]), {a,b}});
                
                }
            }
        }


        return dist[n-1][n-1];

    }
};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        deque <pair<int,int>> dq ;
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        int nebor[4][2] = {0,1,0,-1,1,0,-1,0};

        dq.push_back({0,0});
        dist[0][0] = grid[0][0];

        while(!dq.empty()){
            pair<int,int> popped = dq.front();
            dq.pop_front();
            int i = popped.first;
            int j = popped.second;
            int o = dist[i][j];

            if ( i == m-1 && j == n-1)
                break;

            for ( int k =0 ; k < 4 ; k++){
                int a = i+nebor[k][0];
                int b = j+nebor[k][1];

                if ( a < 0 || b < 0 || a >= m || b >= n)continue;
                if ( dist[a][b] > o+grid[a][b]){
                    dist[a][b] = o+grid[a][b];
                    if ( grid[a][b] == 0 ) dq.push_front({a,b});
                    else dq.push_back({a,b});
                }
            }
        }

        return dist[m-1][n-1];
    }
};
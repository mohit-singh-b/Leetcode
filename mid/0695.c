class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i = 0 , j = 0 , max = 0 , area = 0, a , b  ;
        int m[4][2] = {0,1,0,-1,1,0,-1,0};
        queue <pair<int,int>> q;

        for ( i = 0 ; i < grid.size() ; i++){
            for ( j = 0 ; j < grid[0].size() ; j++){
                if ( grid[i][j] == 0)
                    continue;

                q.push({i,j});
                grid[i][j] = 0;
                area = 0;
                while ( q.empty() == false){
                    auto p = q.front();
                    q.pop();
                    area++;

                    for ( int k = 0 ; k < 4 ; k ++){
                        a = m[k][0];
                        b = m[k][1];
                        if ( a+p.first < 0 || b+p.second < 0 || a+p.first >= grid.size() || b + p.second>= grid[0].size())
                            continue;
                        if ( grid[a+p.first][b+p.second] == 1){
                            q.push({a+p.first,b+p.second});
                            grid[a+p.first][b+p.second] = 0;
                            
                        }
                    }
                }
                max = area > max ? area : max;
            }
        }

        return max;
    }
};
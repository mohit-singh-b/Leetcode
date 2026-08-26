class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for ( int i = 0 ; i < m ; i++){
            for ( int j = 0 ; j < n ; j++){
                if(!i && !j) continue;
                if (!i) {grid[0][j] += grid[0][j-1];continue;}
                if (!j){grid[i][0] += grid[i-1][0];continue;}
                
                grid[i][j] +=min(grid[i-1][j],grid[i][j-1]);}
        }

        return grid[m-1][n-1];
    }
};
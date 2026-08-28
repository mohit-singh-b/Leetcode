class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int  n = matrix[0].size();
        int max_len =1;
        vector<vector<int>> memo(m,vector<int>(n,0));

        for ( int i = 0 ; i < m ; i++){
            for ( int j = 0 ; j < n ; j++)
                max_len = max(dfs(memo,matrix,i,j),max_len);
        }


        return max_len;
    }
    int dfs(vector<vector<int>>& memo,vector<vector<int>>& matrix , int i , int j ){
        int map[4][2] = {1,0,-1,0,0,-1,0,1};
        int max_len = 1;
        if( memo[i][j]) return memo[i][j];

        for ( int k = 0 ; k < 4 ; k++){
            int a = i+map[k][0];
            int b = j+map[k][1];
            if ( a < 0 || b < 0 || a >= matrix.size() || b >= matrix[0].size())
                continue;
            if(matrix[i][j] >  matrix[a][b])
                max_len = max(max_len,1+dfs(memo,matrix,a,b)); 
        }

        
        return memo[i][j] = max_len;

    }
};
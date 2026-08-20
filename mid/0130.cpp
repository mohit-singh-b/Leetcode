class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue <pair<int,int>> q;
        int map[4][2] = {1,0,-1,0,0,1,0,-1};
        int m = board.size() , n = board[0].size() ;

        for ( int i = 0 ; i < m ; i++){
            if ( board[i][0] == 'O'){
                board[i][0] = '1';
                q.push({i,0});
            }
            if ( board[i][n-1] == 'O'){
                board[i][n-1] = '1';
                q.push({i,n-1});
            }
        }
        for ( int i = 0 ; i < n ; i++){
             if ( board[0][i] == 'O'){
                board[0][i] = '1';
                q.push({0,i});
            }
            if ( board[m-1][i] == 'O'){
                board[m-1][i] = '1';
                q.push({m-1,i});
            }
        }

        while ( !q.empty()){
            pair <int,int> popped = q.front();
            q.pop();
            int i = popped.first;
            int j = popped.second;

            for (int k = 0 ; k < 4 ; k++){
                int a = i+map[k][0];
                int b = j+map[k][1];
                
                if ( a < 0 || b < 0 || a >= m || b >= n)continue;
                if ( board[a][b] == 'O'){
                    board[a][b] = '1';
                    q.push({a,b});
                }
            }
        }

        for ( int i = 0 ; i < m ; i++){
            for ( int j= 0 ; j < n ; j++){
                if ( board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '1' ) board[i][j] = 'O';
            }
        }


    
    }
};
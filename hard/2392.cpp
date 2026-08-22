class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector <int> rows , cols;
        vector<vector<int>> res(k,vector<int>(k,0));
        rows = topsort(rowConditions,k);
        cols = topsort(colConditions,k);

        if ( !rows.size() || !cols.size() ) return {};

        for ( int i = 0 ; i < k ; i++){
            for ( int j = 0 ; j < k ; j++){
                if (rows[i] == cols[j]){
                    res[i][j] = rows[i]+1;
                }
            }
        }

        return res;



    }

    vector <int> topsort(vector<vector<int>>& list ,int k){
        vector<vector<int>> graph(k);
        vector<int> dep(k,0);
        queue <int> q;
        vector<int> res;

        for ( auto& e : list){
            int up = e[0]-1;
            int dow = e[1]-1;

            dep[dow]++;
            graph[up].emplace_back(dow);
        }

        for ( int i = 0 ; i < k ; i++){
            if ( dep[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int popped = q.front();
          
            res.emplace_back(popped);
            q.pop();
            for ( auto& e : graph[popped]){   
                dep[e]--;
                if(dep[e] == 0)
                    q.push(e);
            }
        }
        

        
        if ( res.size() != k)
            return {};
        return res;


    }
};
class dsu{
    vector<int> size,parent;
    public:
        dsu(int n){
            size.resize(n,1);
            parent.resize(n);
            for ( int i = 0 ; i < n ; i++)
                parent[i] = i;
        }

        int root(int n){
            if (parent[n] == n)return n;
            return parent[n] = root(parent[n]);
        }
        bool unions(int a , int b){
            int ra = root(a);
            int rb = root(b);
            if (ra == rb)return false;
            if ( size[rb] > size[ra]){
                parent[ra] = rb;
                size[rb]+=size[ra];
            }else{
                parent[rb] = ra;
                size[ra]+=size[rb];
            }
            return true;
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        dsu ds1(accounts.size());
        unordered_map <string,int> hash;
        vector <int> index(accounts.size(),-1);
        vector <vector<string>> res;
        

        for ( int i =0 ; i < accounts.size() ; i++){
            vector <string> account = accounts[i];
            for ( int j = 1 ; j < account.size() ; j++){
                string email = account[j];
                if ( !hash.contains(email)){
                    hash[email] = i;
                    continue;
                }
                else{
                ds1.unions(i,hash[email]);
                }
            }
        }

        for ( int i = 0 ; i < accounts.size() ; i++){
            auto account = accounts[i];
            string name = account[0];
            int root = ds1.root(i);
            if ( index[root] == -1){
                res.push_back({name});
                index[root] = res.size()-1;
                for ( int j = 1 ; j < account.size() ; j++){
                     if (hash[account[j]] != -1){
                        res[index[root]].emplace_back(account[j]);
                        hash[account[j]] = -1;}
                }
            }else{
                for ( int j = 1 ; j < account.size() ; j++){
                    if (hash[account[j]] != -1){
                        res[index[root]].emplace_back(account[j]);
                        hash[account[j]] = -1;}
                }
            }
        }

        for ( auto& account : res){
            sort(account.begin()+1, account.end());
        }
        return res;   
    
    }

    bool static comp(const vector<string> a , const vector<string> b ){
        if ( a[0] < b[0])return true;
        return false;
    }
};
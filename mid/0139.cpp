class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1);
        unordered_map <int,vector<string>> hash;
        vector<int> lens;
        

        for ( auto& word : wordDict){
            int len = word.length();
            if(!hash.contains(len))
                lens.emplace_back(len);
            hash[len].emplace_back(word);
            
        }

        sort(lens.begin(),lens.end());
        dp[0] = true;
        for ( int i = 0 ; i < n ; i++){
            int j = i+1;
            for ( int& len : lens){       
                if ( j-len < 0 )break;
                if (!dp[j-len]) continue;
                
                for ( string& word : hash[len]){
                   
                    if ( word == s.substr(i-len+1,len)){
                        dp[j] = true;
                        break;
                    }
                }
            }
        }

        return dp.back();


    }
};
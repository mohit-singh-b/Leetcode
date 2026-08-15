class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> res ;
        vector <pair<int,int>> in(26,{-1,-1});
        int count = 0;

        for ( int i = 0 ; i < s.size() ; i++){
            char ch = s[i];
            if (in[ch-'a'].first == -1 ) {
                in[ch-'a'].first = i;
                in[ch-'a'].second = i;
                continue;
            }
            in[ch-'a'].second = i;            
        }

        sort(in.begin(),in.end());
        int i;
        for (  i = 0 ; i < 26 ; i++ ){
            if ( in[i].first == -1)
                continue;
            else 
                break;
        }

        pair<int,int> prevpair = in[i];

        for ( i = i+1; i < 26 ; i++ ){
            if (in[i].first > prevpair.second ){
                int count = prevpair.second - prevpair.first +1;
                res.emplace_back(count);
                prevpair = in[i];
            }
            prevpair.second = max(prevpair.second,in[i].second);

        }
        count = prevpair.second - prevpair.first +1;
        res.emplace_back(count);

        return res;
    }
};
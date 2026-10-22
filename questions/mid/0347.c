class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue < pair<int,int> , vector <pair<int,int> > , greater<pair<int,int> > > pq;
        vector <int> res;
        unordered_map <int,int> hash;

        for ( int e : nums){
            hash[e]++;
        } 

        for ( auto [e,f] : hash){
            pq.push({f,e});
            if ( pq.size() >= k+1)
            pq.pop();
        }
        if ( pq.size() > k)
            pq.pop();

        while  ( !pq.empty()){
            auto pair = pq.top();
            pq.pop();
            res.emplace_back(pair.second);
        }
        return res;
    }
};
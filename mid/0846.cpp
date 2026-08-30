class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map <int,int> hash;
        int flag = 0;
        sort(hand.begin(),hand.end());
        for ( int e : hand)
            hash[e]++;

        for ( int e : hand){
            if ( !hash[e])continue;
            hash[e]--;
            for ( int i = 1; i < groupSize ; i++){
                if (!hash[e+i]) {return false;}
                hash[e+i]--;
            }
        }
        return true;


    }
};
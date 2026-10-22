class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int mask = 0;
        int x = target[0];
        int y = target[1];
        int z = target[2];

        for ( auto& triplet : triplets ){
            int a = triplet[0];
            int b = triplet[1];
            int c = triplet[2];

            if ( a == x && b <= y && c <= z)
                mask = mask | (1);
            if ( b == y && a <= x && c <= z)
                mask = mask | (1<<1);
            if ( c == z && a <= x && b <= y)
                mask = mask | (1<<2);
        }

        if ( mask == 7 ) return true;
        return false;
    }
};
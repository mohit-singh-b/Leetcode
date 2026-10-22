class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        int left = -maxJump+minJump, size  = maxJump-minJump ;
        int count = 1;
        s[0] = '2';

        for ( int i = minJump ; i < n ; i++){
            if ( count > 0 && s[i] == '0')
                s[i] = '2';
            
            if ( left >= 0 && s[left] == '2')
                count--;
            left++;
            if ( s[left+size] == '2')
                count++;
        }

        return s[n-1] == '2';   

    }
};
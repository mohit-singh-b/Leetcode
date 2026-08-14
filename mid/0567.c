class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int map[26] = {0};
        int i = 0 , j = 0 ;

        if ( s1.size() > s2.size())
            return false;

        if ( s1.size()== 0)
            return true;
            
        for ( char c : s1){
            map[c-'a']++;
        }

        for ( i = 0 ; i < s2.size() ; i++){
            map[s2[i]-'a']--;

            while ( j <= i && map[s2[i]-'a'] < 0 ){
                map[s2[j]-'a']++;
                j++;
            }
            if ( i - j +1 == s1.size())
                return true;
        }

        return false;
    }
};
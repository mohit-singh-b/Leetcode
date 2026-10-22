class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int len=0;
        int map[3] = {0};
        int i = 0;
        for (  i = 0 ; i < n ; i++){
            if ((map[0]>= k) && (map[1] >=k)&& (map[2] >= k))break;
            map[s[i]-'a']++;
            len++;
        }
        if ( (map[0]< k) || (map[1] <k)|| (map[2] < k)) return -1;
        
        int j = -1;
        for ( i=i-1; i >= -1 ; i-- ){
            while( ((map[0]< k) || (map[1] <k)|| (map[2] < k)) && i+j+2 < len){
                j++;

                map[s[n-j-1]-'a']++;
            }

            if ((map[0]>= k) && (map[1] >=k)&& (map[2] >= k)) len = min(len,i+j+2) ;

            if ( i!= -1) map[s[i]-'a']--;

        }

        return len;


    }
};
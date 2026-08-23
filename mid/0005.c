class man{
    public : 
    string t;
    int mx =1,max_i=0;
    vector<int> p;

    man(string s){
        int n = s.size();
        t.resize(2*n+1,'#');
        for (int i = 0 ; i < n ; i++)
            t[i*2+1] = s[i];

        create_p(n);
    }

    void create_p(int n){
        p.resize(2*n+1,1);
        int l = -1,r = 1,N= 2*n+1;

        for (int i = 1 ; i < N ; i++){
            if (i<r) p[i] = min(r-i,p[l+r-i]);
            int a = i-p[i], b = i+ p[i];
            
            while(a >= 0 && b < N){
                if ( t[a] == t[b]){
                    p[i]++;
                    a--;
                    b++;
                }else break;
            }


            if ( b > r ) {
                r = b ; l = a;
            }
    
            if ( mx < p[i] ) {
                mx = p[i];
                max_i = i;
            }
        }
    }

    void display(){
        for (int  i = 0 ; i < p.size();i++)
            cout << t[i] << " "; cout << endl;
        for (int  i = 0 ; i < p.size();i++)
            cout << p[i] << " "; cout << endl;
        
    }

    int get_length(int c , bool odd){
        int pos = 2*c+1 +(!odd);
        return p[pos]-1;
    }

    bool is_palindrome(int l ,int r ){
        int c = (r-l)/2;
        if ( l-r+1 <= get_length(c,l%2 == r%2)) return true;
        return false;
    }

};

class Solution {
public:
    string longestPalindrome(string s) {
        man man1(s);
        int i = (man1.max_i-1) /2;
        int st , en;
        int oddlen = man1.get_length(i,true);
        int evenlen = man1.get_length(i,false);

        if ( evenlen > oddlen){st = i-(evenlen/2-1);en = i+evenlen/2;}
        else {st = i-oddlen/2 ; en = i+oddlen/2;}

        string res;
        cout << st << " " << en;
        for ( i = st ; i <= en ; i++)
            res+=s[i];

        return res;       
    }
};
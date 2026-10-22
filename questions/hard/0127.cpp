class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> hash;
        int steps=1;
        queue <string> q;
        for ( string& word : wordList){
            hash.insert(word);
        }

        q.push(beginWord);
        while(!q.empty()){
            int lvl = q.size();
            for ( int count = 0 ; count < lvl ; count++)
                {string popped = q.front();
                q.pop();
                
                if (popped == endWord )return steps;
                for ( int i = 0 ; i < popped.size() ; i++){
                    char temp = popped[i];

                    for ( char c = 'a' ; c <= 'z' ; c++){
                        popped[i] = c;
                        if ( hash.contains(popped)){
                            q.push(popped);
                            hash.erase(popped);
                        }
                    }                    
                    popped[i] = temp;
                }
            }
            steps++;
        }

        return 0;

    }
};
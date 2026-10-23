#include <bits/stdc++.h>
using namespace std;

class trie{
    array<trie*,26> children =  {0};
    bool eow  = false;
    public:
    trie() = default;
    ~trie(){
        for ( int i = 0 ; i < 26 ; i++) delete children[i];
    }
    trie(const trie&) = delete ;
    trie& operator=(const trie&) = delete;

    void add(const string& s){
        trie* ptr = this;
        for ( char c : s){
            if ( !ptr->children[c-'a']) ptr->children[c-'a'] = new trie;
            ptr = ptr->children[c-'a'];
        }
        ptr->eow = true;
    }

    bool check(const string& s){
        trie* ptr = this;
        for ( char c : s){
            if ( !ptr->children[c-'a']) return false;
            ptr = ptr->children[c-'a'];
        }
        return ptr->eow;
    }

};
class RandomizedSet {
public:
    unordered_map <int,pair<bool,int>> hash;
    vector <int> a;
    RandomizedSet() {        
    srand(time(0));
    }
    
    bool insert(int v) {
        if ( hash[v].first == true)
            return false;
        hash[v].first= true;
        a.emplace_back(v);
        hash[v].second = a.size()-1;
        return true;
    }
    
    bool remove(int v) {
        if ( hash[v].first == false)
            return false;
        hash[v].first = false;
        a[hash[v].second] = a[hash[a.back()].second];
        hash[a.back()].second = hash[v].second;
        a.pop_back();
        return true;
    }
    
    int getRandom() {
        if (a.size() == 1)
            return a[0];
        return a[rand()%(a.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
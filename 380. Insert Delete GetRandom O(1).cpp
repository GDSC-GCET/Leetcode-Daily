class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()){
            return false;
        }
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            int i = m[val];
            int last = v.back();
            v.back() = val;
    
            v[i] = last;
            m[last] = i;
            v.pop_back();
            m.erase(val);
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int num = rand() % v.size();
        return v[num]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

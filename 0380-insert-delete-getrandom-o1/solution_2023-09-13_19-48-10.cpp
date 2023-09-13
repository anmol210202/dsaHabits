class RandomizedSet {
public:
    unordered_set<int> mySet;
    //constructor
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mySet.find(val)!=mySet.end()) return false;
        else {
            mySet.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mySet.find(val)==mySet.end()) return false;
        else {
            mySet.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int n= rand()%mySet.size();
        auto it =mySet.begin();
        advance(it,n);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

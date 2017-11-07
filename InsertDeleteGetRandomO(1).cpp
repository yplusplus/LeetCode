class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hash_table_.count(val)) return false;
        hash_table_[val] = (int)nums_.size();
        nums_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = hash_table_.find(val);
        if (it == hash_table_.end()) return false;
        int idx = it->second;
        hash_table_.erase(it);
        if (nums_.back() != val) {
            nums_[idx] = nums_.back();
            hash_table_[nums_.back()] = idx;
        }
        nums_.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums_[rand() % nums_.size()];
    }
private:
    vector<int> nums_;
    unordered_map<int, int> hash_table_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
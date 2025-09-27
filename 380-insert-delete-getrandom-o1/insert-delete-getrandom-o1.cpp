class RandomizedSet {
public:
    unordered_map<int, int> mp; // value -> index in vector
    vector<int> nums;           // stores elements

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val)) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) return false;
        
        int idx = mp[val];
        int last = nums.back();
        
        // Swap val ith last element
        nums[idx] = last;
        mp[last] = idx;
        
        nums.pop_back();
        mp.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
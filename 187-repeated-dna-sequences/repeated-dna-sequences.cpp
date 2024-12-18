class Solution {
public:
    vector<string> findRepeatedDnaSequences(string ss) {
        vector<std::string> res;
        unordered_map<string, int> tmp;
        string s = ss.substr(0,10);
        int limit = ss.size();
        for (int i = 10; i < limit; i++) {
            tmp[s]++;
            s = s.substr(1) + ss[i];
        }
        tmp[s]++;
        for (auto item: tmp) {
            if (item.second > 1) res.push_back(item.first);
        }
        return res;
    }
};
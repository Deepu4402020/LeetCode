class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0; 
        bool found = false;

        for (auto i : s) {
            found = false; 
            for (int j = idx; j < t.length(); j++) {
                if (i == t[j]) {
                    found = true;
                    idx = j + 1; 
                    break;       
                }
            }
            if (!found) return false; 
        }
        return true;
    }
};
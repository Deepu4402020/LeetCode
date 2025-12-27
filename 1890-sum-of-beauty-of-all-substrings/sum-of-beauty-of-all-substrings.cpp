class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;  
                
                int maxi = 0;
                int mini = 500;
                for (auto it : mp) {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                
                sum += (maxi - mini);
            }
        }
        
        return sum;
    }
};
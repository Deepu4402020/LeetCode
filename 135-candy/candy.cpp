class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        if (n == 0) return 0;

        vector<int> preLess(n, 1);   
        vector<int> suffLess(n, 1);  

        for (int i = 1; i < n; i++) {
            if (r[i] > r[i - 1]) {
                preLess[i] = preLess[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (r[i] > r[i + 1]) {
                suffLess[i] = suffLess[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(preLess[i], suffLess[i]);
        }

        return ans;
    }
};
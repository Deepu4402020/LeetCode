#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        if (n/m <   k) return -1; 

        int l = *min_element(b.begin(), b.end());
        int r = *max_element(b.begin(), b.end());
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0, boquet = 0;

            for (int i = 0; i < n; i++) {
                if (b[i] <= mid) {
                    cnt++;  
                    if (cnt == k) { 
                        boquet++;
                        cnt = 0;
                    }
                } else {
                    cnt = 0; 
                }
            }

            if (boquet >= m) {
                ans = mid;
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans;
    }
};


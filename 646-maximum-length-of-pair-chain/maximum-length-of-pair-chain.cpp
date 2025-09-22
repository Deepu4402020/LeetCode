#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int curr_end = INT_MIN;

        for (auto &p : pairs) {
            if (p[0] > curr_end) {
                count++;
                curr_end = p[1];
            }
        }

        return count;
    }
};
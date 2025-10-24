#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        t[0][0] = triangle[0][0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    t[i][j] = triangle[i][j] + t[i - 1][j];
                } else if (j == i) {
                    t[i][j] = triangle[i][j] + t[i - 1][j - 1];
                } else {
                    t[i][j] =
                        triangle[i][j] + min(t[i - 1][j - 1], t[i - 1][j]);
                }
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, t[n - 1][j]);
        }
        return mini;
    }
};
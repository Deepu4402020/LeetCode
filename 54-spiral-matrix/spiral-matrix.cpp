class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> arr;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; ++j) {
                arr.push_back(matrix[top][j]);
            }
            ++top;
            for (int i = top; i <= bottom; ++i) {
                arr.push_back(matrix[i][right]);
            }
            --right;
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    arr.push_back(matrix[bottom][j]);
                }
                --bottom;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    arr.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return arr;
    }
};
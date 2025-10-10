class Solution {
public:
    int mem[501][501];
    int solve(string& s, string& t, int i1, int i2) {
        // Base Case
        if (i2 >= t.size()) {
            return s.size() - i1;
        }
        if (i1 >= s.size())
            return t.size() - i2;

        // Memo
        if (mem[i1][i2] != -1)
            return mem[i1][i2];

        if (s[i1] == t[i2])
            return mem[i1][i2] = solve(s, t, i1 + 1, i2 + 1);

        // Insert
        int i = 1 + solve(s, t, i1 , i2 + 1);
        // Delete
        int d = 1 + solve(s, t, i1 + 1, i2);
        // Replace
        int r = 1+solve(s, t, i1 + 1 , i2 + 1);

        return mem[i1][i2] = min({i, r, d});
    }
    int minDistance(string word1, string word2) {
        memset(mem, -1, sizeof(mem));
        return solve(word1, word2, 0, 0);
    }
};
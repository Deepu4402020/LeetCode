class Solution {
public:
    void gen_all_comb(int i, string curr,
                      vector<string>& combi_of_string,
                      vector<string>& ans) {
        if (i == combi_of_string.size()) {
            ans.push_back(curr);
            return;
        }

        for (char ch : combi_of_string[i]) {
            gen_all_comb(i + 1, curr + ch, combi_of_string, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        map<char, string> mpp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> combi_of_string;
        for (char d : digits) {
            combi_of_string.push_back(mpp[d]);
        }

        vector<string> ans;
        gen_all_comb(0, "", combi_of_string, ans);
        return ans;
    }
};
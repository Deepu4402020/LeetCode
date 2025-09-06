class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> vec(26, 0);
        int idx = 0;
        for (char ch : order) {
            vec[ch - 'a'] = idx++;
        }

        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            string word1 = words[i];
            int n1 = word1.length();
            string word2 = words[i + 1];
            int n2 = word2.length();

            for (int j = 0; j < n1; j++) {

                if (j >= n2)
                    return false;

                if (word1[j] != word2[j]) {
                    if (vec[word1[j] - 'a'] > vec[word2[j] - 'a'])
                        return false;
                    else
                        break;
                }
            }
        }
        return true;
    }
};
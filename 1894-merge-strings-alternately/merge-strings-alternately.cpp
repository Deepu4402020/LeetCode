class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        string ans;
        int i = 0;
        while (i < n1 && i < n2){
            ans += word1[i] ;ans+= word2[i];i++;}

        while (i < n1){
            ans += word1[i];i++;
}
        while (i < n2){
            ans += word2[i];
i++;}
        return ans;
    }
};
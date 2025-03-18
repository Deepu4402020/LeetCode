class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = 0, b = 0, c = 0;  
        int st = 0, ans = 0;  

        for (int right = 0; right < s.length(); right++) {
            if (s[right] == 'a') a++;
            if (s[right] == 'b') b++;
            if (s[right] == 'c') c++;

            while (a > 0 && b > 0 && c > 0) {
                ans += s.length() - right; 
                if (s[st] == 'a') a--;
                if (s[st] == 'b') b--;
                if (s[st] == 'c') c--;
                st++;  
            }
        }
        return ans;
    }
};
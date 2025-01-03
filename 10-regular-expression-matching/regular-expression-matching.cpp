class Solution {
    vector<vector<int>> dp;
    bool helper(string& s, string& p, int s_idx, int p_idx){
        int sn = s.size();
        int pn = p.size();

        if(p_idx == pn){
            if(s_idx == sn){
                return true;
            }
            return false;
        }


        if(dp[s_idx][p_idx] != -1){
            return dp[s_idx][p_idx];
        }


        bool ans = false;
        bool curr = (s_idx < sn) and (s[s_idx] == p[p_idx] or p[p_idx] == '.');

        if(p_idx + 1 < pn and p[p_idx + 1] == '*'){
            ans = ans or helper(s, p, s_idx, p_idx+2);
            ans = ans or (curr and helper(s, p, s_idx+1, p_idx));
        }
        else if(curr){
             ans = ans or helper(s, p, s_idx+1, p_idx+1);
        }

        return dp[s_idx][p_idx] = ans;
    }
public:
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(s, p, 0, 0);
    }
};
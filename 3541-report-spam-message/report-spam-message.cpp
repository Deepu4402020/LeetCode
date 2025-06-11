class Solution {
public:
    bool reportSpam(vector<string>& m, vector<string>& bw) {
        unordered_set<string> st(bw.begin(),bw.end());
        int n=m.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(st.find(m[i])!=st.end()) cnt++;
        }
        return (cnt>=2);
    }
};
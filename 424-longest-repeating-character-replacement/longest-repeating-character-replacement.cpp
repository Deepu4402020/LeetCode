class Solution {
public:
    int characterReplacement(string s, int k) {
        vector <int> mp(26,0);
        int n=s.length(),l=0,r=0,maxlen=0,len,maxf=0;
        while(r<n)
        {
            mp[s[r]-'A']++;
            maxf=max(maxf,mp[s[r]-'A']);
            if((r-l)+1-maxf>k)
            {
                mp[s[l]-'A']--;
                l=l+1;
            }

            len=(r-l)+1;
            maxlen=max(maxlen,len);
            
            r++;
        }
        return maxlen;
    }
};
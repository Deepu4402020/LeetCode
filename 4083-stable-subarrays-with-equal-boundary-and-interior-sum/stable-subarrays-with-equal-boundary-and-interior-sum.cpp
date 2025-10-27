class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        int n=c.size();
        vector<long long > pref(n);
      pref[0]=(long long)c[0];
        for (int i = 1; i <n ; i++) {
            pref[i] = pref[i-1]+(long long )c[i];
        }//<prefSum ,<a[i],freq> >
         map<long long, map<long long, long long>> mp;
        long long cnt = 0;
        for (int i = 1; i < n; i++) {
            long long need = pref[i] - c[i] * 2;
            cnt += mp[need][c[i]];
            mp[pref[i-1]][c[i-1]]++;
        }
        return cnt;
    }
};
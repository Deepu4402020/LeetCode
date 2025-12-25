class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        const int n=happiness.size();
        sort( happiness.begin(), happiness.end());
        
        long long sum=0;
        for(int i=0; i<k; i++){
            long long x=max(0, happiness[n-1-i]-i);

            sum+=x;
        }
            
        return sum;
        
    }
};
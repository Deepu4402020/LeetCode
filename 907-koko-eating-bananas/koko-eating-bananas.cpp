class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 1;
        for(int x : piles){
            r = max(r, x);
        }
        
        while(l<r) {
            int mid = l + (r-l)/2;
            int hrs = 0;
            for(int x: piles){
                hrs += ceil(x*1.0/mid);
            }
            if(hrs<=h){
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};
class Solution {
public:
    int maximum(vector<int> p){
        int maxi=0;
        for(auto it:p){
            if(it>maxi){
              maxi=it;
            }
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;int ans=1;
        if(piles.size()==1) ceil(h/piles[0]);
        int j=maximum(piles);
        
        while(i<=j){
            int mid=(i+j)/2;
            long long hrs=0;
            for(auto it:piles){
                hrs+=(it+mid-1)/mid;
            }

            if(hrs<=h) j=mid-1;
            else i=mid+1; 
            
            
        }
        
        return i;
    }
};
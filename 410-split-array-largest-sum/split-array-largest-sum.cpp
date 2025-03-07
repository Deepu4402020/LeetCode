class Solution {
public:       
 int countsubarr(vector<int>& a,int maxsum,int n){
        int count=1;
        long long subarrsum=0;
        for(int i=0;i<n;i++){
            if(subarrsum+a[i]<=maxsum)
            subarrsum+=a[i];
            else{
                subarrsum=a[i];
                count++;
            }
        }
        return count;
    }
    int sumarr(vector<int>& a,int n){
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=a[i];
        return sum;
    }
    int max_element(vector<int>& a, int n){
        int maxi=a[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,a[i]);
        }
        return maxi;
    }
    int splitArray(vector<int>& a, int k) {
        if(a.size()<k)
        return -1;
        int n=a.size();
        int low=max_element(a,n);
        int high=sumarr(a,n);
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=countsubarr(a,mid,n);
            if(cnt<=k)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};
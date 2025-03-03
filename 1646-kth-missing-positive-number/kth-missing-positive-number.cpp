class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0; int r=arr.size()-1;
        while(l<=r){
            int mid=(r-l)/2+l;
            if(arr[mid]-mid-1<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l+k;

    }
};
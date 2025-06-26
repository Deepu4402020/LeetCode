class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //log(m+n)
        int m=nums1.size();
        int n=nums2.size();
        int mid=0;
        int cnt=0;
        int mid2=0; int i=0,j=0;
        while((i<m||j<n) && (m+n)/2>=cnt){
       mid2=mid;
if(i<m&&j<n){
        if(nums1[i]<=nums2[j]){
         //   mid2=mid;
        mid=nums1[i++];cnt++;
        }


        else {
        // mid2=mid;
         mid=nums2[j++];cnt++;
        }
}
else if(i<m){
    mid=nums1[i++];cnt++;
}
else {
    mid=nums2[j++];cnt++;
}
        }
        if((m+n)%2==0) return (double)((double)(mid+mid2)/2);


        return (double)(mid);
          
    }
};
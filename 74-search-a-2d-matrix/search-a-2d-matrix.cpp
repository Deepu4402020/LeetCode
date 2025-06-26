class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
       int c=matrix[0].size();
       int r=matrix.size(); 
       int i=0;int j=r*c-1;
       while(i<=j){
       int mid=(i+j)/2;
        if(matrix[mid/c][abs(mid-(mid/c)*c)]==target) return true;

        if(target>matrix[mid/c][abs(mid-(mid/c)*c)]){
            i=mid+1;
        }
        else j=mid-1;
       }
       return false;
    }
};
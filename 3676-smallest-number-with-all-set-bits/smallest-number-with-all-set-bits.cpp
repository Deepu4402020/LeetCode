class Solution {
public:
    int smallestNumber(int n) {
        int cnt=0;
        while(n!=0){
            n>>=1;cnt++;
        }
        return (1<<cnt)-1;
    }
};
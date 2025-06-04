class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int>pq;
        while(n){
            pq.push(n%10);
            n/=10;
        }
        int temp = pq.top();
        pq.pop();
        return temp*pq.top();
    }
};
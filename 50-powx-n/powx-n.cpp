class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        bool sign = false;
        long long power = n;
        if(power<0){
            sign = true;
            power = -power;
        }
        while(power>0){ 
            if(power&1) ans = ans*x;  // odd power
            x = x*x;
            power>>=1; // divide by 2
        }
        return sign==true? 1.0/ans: ans; // power negative hai to 1 se divide hoga answer
    }
};
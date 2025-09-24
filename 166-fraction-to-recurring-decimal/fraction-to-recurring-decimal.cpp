class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;
        
        if ((long )numerator * denominator < 0) res += "-";

        long n = abs((long)numerator);
        long d = abs((long)denominator);

        // Integer part
        res += to_string(n / d);

        long rem = n % d;
        if (rem == 0) return res; 

        res += ".";
        unordered_map<long , int> mp; // remainder -> position in res

        while (rem != 0) {
            if (mp.count(rem)) {
                res.insert(mp[rem], "(");
                res += ")";
                break;
            }

            mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }

        return res;
    }
};
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int key = 0, pow10 = 1;
        while (num1 && num2 && num3) {
            int a = num1 % 10, b = num2 % 10, c = num3 % 10;
            int mini = min({a, b, c});
            key += mini * pow10;
            pow10 *= 10;
            num1 /= 10; num2 /= 10; num3 /= 10;
        }
        return key;
    }
};
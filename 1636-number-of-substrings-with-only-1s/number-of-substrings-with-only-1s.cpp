class Solution {
public:
	int numSub(string s) {
		long count = 0;
		long ans = 0;
		for(int i  = 0; i < s.size(); i++){
			if(s[i] == '1'){
				count++;
			}
			else{
				ans += (count * (count + 1)) / 2;
				count = 0;
			}
		}
		return (ans + (count * (count + 1)) / 2) % 1000000007;
	}
};
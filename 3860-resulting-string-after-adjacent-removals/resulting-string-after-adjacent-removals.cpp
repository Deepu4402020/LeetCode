class Solution {
public:
    string resultingString(string s) {
        string sb;
        
        for (char ch : s) {
            if (!sb.empty()) {
                char top = sb.back();
                int diff = abs(top - ch);
                
                if (diff == 1 || diff == 25) {
                    sb.pop_back();
                    continue;
                }
            }
            sb.push_back(ch);
        }
        
        return sb;
    }
};
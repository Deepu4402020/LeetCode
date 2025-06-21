class Solution {
public:
    int ladderLength(string a, string b, vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> s;

        for (auto i : wordList) {
            s.insert(i);
        }
        if (s.find(b)==s.end()) {
            return 0;
        }
        q.push({a, 1});
        if (s.find(a)!=s.end()) {
            s.erase(a);
        }

        while (!q.empty()) {
            
            string t_str = q.front().first;
            int steps = q.front().second;
            if(t_str==b) return steps;
            q.pop();


            for (int k=0;k<a.size();k++) {
                string temp=t_str;
                for (char i = 'a'; i <= 'z'; i++) {
                    temp[k]=i;
                    if(temp==t_str) continue;

                    if(s.find(temp)!=s.end()){
                        q.push({temp,steps+1});
                        s.erase(temp);
                    }

                }
            }
            
        }

        return 0;
    }
};
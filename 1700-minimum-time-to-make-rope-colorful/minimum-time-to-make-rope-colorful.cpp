class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int time = 0;
        int l_max = 0;
        for (int i = 0; i < n; i++) {

            if (colors[i] == colors[i + 1]) {
                while (i < n - 1 && colors[i] == colors[i + 1]) {
                    time += neededTime[i];
                    l_max = max(l_max, neededTime[i]);
                    i++;
                }
                if(colors[i]==colors[i-1]){
                    time += neededTime[i];
                    l_max = max(l_max, neededTime[i]);
                }
                time -= l_max;
                l_max = 0;
            }
        }
        return time;
    }
};
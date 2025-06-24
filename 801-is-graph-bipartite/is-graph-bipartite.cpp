class Solution {
public:
    /*do set lo unko

    */
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> v(n, 0);

        for (int i = 0; i < n; i++) {
           if(v[i]!=0) continue;

           q.push(i);
           v[i]=1;
           while(!q.empty()){
            int node =q.front();q.pop();
            for( int i: graph[node]){
                if(v[i]==0){
                    v[i]= -v[node];
                    //cout<<v[i]<<" ";
                    q.push(i);
                }else if(v[i]==v[node]) return false;
            }
           }
            
            
        }return true;
    }
};
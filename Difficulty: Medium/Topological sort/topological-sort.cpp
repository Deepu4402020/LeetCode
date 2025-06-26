class Solution {
  public:
  void dfs( int node,vector<vector<int>>&adj, vector<int>&vis,stack<int>&stk){
     vis[node]=1;
     for(int it:adj[node]){
         if(!vis[it]){
             dfs(it,adj,vis,stk);
         }
     }stk.push(node);
  }
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) {
        // code here
        vector<int>vis(v,0);
        stack<int> stk;
        vector<vector<int>> adj(v);
        for(auto it :edges){
            int u=it[0];int w=it[1];
            adj[u].push_back(w);
        }
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i, adj,vis,stk);
            }
        }
        vector<int>t_sort;
        while(!stk.empty()){
            t_sort.push_back(stk.top());stk.pop();
        }
        return t_sort;
    }
};
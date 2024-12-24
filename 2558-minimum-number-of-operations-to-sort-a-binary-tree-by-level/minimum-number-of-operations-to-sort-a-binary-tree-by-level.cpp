/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int> arr, int n){
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
    vector<bool> vis(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i) continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = arrPos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0)
            ans += (cycle_size - 1);
    }
    return ans;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            vector<int>v;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
            }
            ans+=minSwaps(v,v.size());
            v.clear();
        }
        return ans;
    }
};
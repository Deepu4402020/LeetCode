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
    int countSwap(vector<int>& arr){
    map<int, int> reverseIndex;
    for(int i = 0; i < arr.size(); ++i) reverseIndex[arr[i]] = i;
    int i = 0, ans = 0;
    for(auto [k,v] : reverseIndex){
        if(v == i) { i++; continue; }
        reverseIndex[arr[i]] = v;
        swap(arr[i], arr[v]);
        ans++; i++;
    }
    return ans;
}

int minimumOperations(TreeNode* root) {
    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        vector<int> arr;
        for(int n = q.size(); n > 0; --n){
            TreeNode* node = q.front(); q.pop();
            arr.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans += countSwap(arr);
    }
    return ans;
}
};
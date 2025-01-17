/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stac;
        vector<int> ans;TreeNode* current = root;
       
        while (current != nullptr || !stac.empty()) {
            while (current != nullptr) {
                stac.push(current);
                current = current->left;
            }
            current = stac.top();
            stac.pop();
            ans.push_back(current->val);
            current = current->right;
        } 
         return ans;
    }
  

}
;
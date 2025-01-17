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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        stack<TreeNode*> stk2;
        TreeNode* current = root;
        if (current)
            stk.push(current);

        while (!stk.empty()) {
            current = stk.top();
            stk.pop();
            stk2.push(current);

            if (current->left) {
                stk.push(current->left);
            }
            if (current->right) {
                stk.push(current->right);
            }
        }

        vector<int> vec;
        while (!stk2.empty()) {
            vec.push_back(stk2.top()->val);
            stk2.pop();
        }
        return vec;
    }
};
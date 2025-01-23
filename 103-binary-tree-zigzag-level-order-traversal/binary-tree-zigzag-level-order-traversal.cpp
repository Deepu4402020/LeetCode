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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (!root) return v;

        deque<TreeNode*> que;
        que.push_back(root);
        bool leftToRight = true;

        while (!que.empty()) {
            int size = que.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* curr;
                if (leftToRight) {
                    curr = que.front();
                    que.pop_front();
                    level.push_back(curr->val);

                    if (curr->left) que.push_back(curr->left);
                    if (curr->right) que.push_back(curr->right);
                } else {
                    curr = que.back();
                    que.pop_back();
                    level.push_back(curr->val);

                    if (curr->right) que.push_front(curr->right);
                    if (curr->left) que.push_front(curr->left);
                }
            }

            v.push_back(level);
            leftToRight = !leftToRight; // Toggle direction
        }

        return v;
    }
};

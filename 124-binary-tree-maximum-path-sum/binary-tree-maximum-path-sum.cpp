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
 */class Solution {
public:
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

private:
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftMaxPath = max(dfs(node->left), 0);
        int rightMaxPath = max(dfs(node->right), 0);

        int maxIfNodeIsRoot = node->val + leftMaxPath + rightMaxPath;
        maxSum = max(maxSum, maxIfNodeIsRoot);

        return node->val + max(leftMaxPath, rightMaxPath);
    }
};
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
    int dia =0;
    int dfs(TreeNode* root){
        
        if(!root) return 0;

        int leftH=dfs(root->left);

        int rightH=dfs(root->right);
        dia=max(rightH+leftH,dia);

        return max(leftH,rightH)+1;
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return dia;
    }
};
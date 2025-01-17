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
    stack<TreeNode*> st;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* iter = root; // for inserting nodes
        TreeNode *topNode = nullptr, *prevInserted = nullptr; /*to check for
              right subtrees inserted yet or not*/

        while (iter != nullptr || !st.empty()) {
            if (iter !=nullptr) {
                st.push(iter);
                iter = iter->left;
            }
            else {
                topNode =st.top(); 
                if (topNode->right != nullptr &&
                    topNode->right != prevInserted) {
                    iter = topNode->right;
                } else /*both left and right subtrees of this node traversed so insert it in postorder traversal*/
                {
                    ans.push_back(topNode->val);
                    prevInserted = topNode;
                    st.pop();
                }
            }
        }
        return ans;
    }
};
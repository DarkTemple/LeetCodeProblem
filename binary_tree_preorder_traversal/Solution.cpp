/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root) {
            ret.push_back(root->val);
            vector<int> left = preorderTraversal(root->left);
            vector<int> right = preorderTraversal(root->right);
            ret.insert(ret.end(), left.begin(), left.end());
            ret.insert(ret.end(), right.begin(), right.end());
        }
        
        return ret;
    }
};
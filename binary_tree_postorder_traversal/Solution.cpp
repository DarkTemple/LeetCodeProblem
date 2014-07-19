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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root) {
            vector<int> left =  postorderTraversal(root->left);
            vector<int> right =  postorderTraversal(root->right);
            ret.insert(ret.end(), left.begin(), left.end());
            ret.insert(ret.end(), right.begin(), right.end());
            ret.push_back(root->val);
        }
        
        return ret;
    }
};
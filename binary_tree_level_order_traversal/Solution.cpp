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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode *> q1;
        q1.push(root);
        queue<TreeNode *> q2;
        vector<int> valVec;
        while (!q1.empty()) {
            valVec.clear();
            while (!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                valVec.push_back(node->val);
                if (node->left) q2.push(node->left);
                if (node->right) q2.push(node->right);
            }
            
            ret.push_back(valVec);
            q1.swap(q2);
        }
        
        return ret;
    }
};
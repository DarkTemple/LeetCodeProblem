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
    void levelOrderHelper(TreeNode *root, int level, vector<vector<int>> &ret) {
        if (!root) {
            return;
        }
        
        if (level == ret.size()) {
            vector<int> levelVec(1, root->val);
            ret.push_back(levelVec);
        } else {
            ret[level].push_back(root->val);
        }
        
        levelOrderHelper(root->left, level+1, ret);
        levelOrderHelper(root->right, level+1, ret);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        levelOrderHelper(root, 0, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
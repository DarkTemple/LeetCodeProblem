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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        vector<TreeNode *> s1;
        vector<TreeNode *> s2;
        s1.push_back(root);
        while (!s1.empty()) {
            vector<int> level;
            TreeNode *node = NULL;
            while (!s1.empty()) {
                node = s1.back();
                s1.pop_back();
                level.push_back(node->val);
                if (node->left) s2.push_back(node->left);
                if (node->right) s2.push_back(node->right);
            }
            
            if (!level.empty()) ret.push_back(level);
            level.clear();
            while (!s2.empty()) {
                node = s2.back();
                s2.pop_back();
                level.push_back(node->val);
                if (node->right) s1.push_back(node->right);
                if (node->left) s1.push_back(node->left);
            }
            
            if (!level.empty()) ret.push_back(level);
        }
        
        return ret;
    }
};
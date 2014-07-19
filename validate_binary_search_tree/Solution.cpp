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
    bool isBSTHelper(TreeNode *root, int rangeBegin, int rangeEnd) {
        if (!root) return true;
        if (root->val <= rangeBegin || root->val >= rangeEnd) return false;
        return isBSTHelper(root->left, rangeBegin, root->val) && isBSTHelper(root->right, root->val, rangeEnd);
    }
    
    bool isValidBST(TreeNode *root) {
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }
};
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
    int maxDepth(TreeNode *root)  {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) {
            return 0;
        } else {
            int leftHeight = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }
};
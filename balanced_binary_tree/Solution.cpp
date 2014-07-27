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
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalancedHelper(root, height);
    }
    
    bool isBalancedHelper(TreeNode *root, int &height) {
        if (!root) {
            height = 0;
            return true;
        } else {
            int leftHeight = 0, rightHeight = 0;
            bool isLeftBalanced = isBalancedHelper(root->left, leftHeight);
            bool isRightBalanced = isBalancedHelper(root->right, rightHeight);
            height = max(leftHeight, rightHeight) + 1;
            return (isLeftBalanced && isRightBalanced && abs(leftHeight-rightHeight) <= 1);
        }
    }
};
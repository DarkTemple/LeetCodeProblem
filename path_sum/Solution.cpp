class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root) {
            if (isLeaf(root)) {
                return (root->val == sum);
            } else {
                return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
            }
        } else {
            return false;
        }
    }
    
    bool isLeaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }
};
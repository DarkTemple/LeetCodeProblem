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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        if (minLeft == 0) return minRight + 1;
        if (minRight == 0) return minLeft + 1;
        return min(minLeft, minRight) + 1;
    }
};
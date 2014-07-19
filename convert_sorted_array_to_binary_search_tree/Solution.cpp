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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
        if (num.size() == 1) return new TreeNode(num[0]);
        TreeNode *root = new TreeNode(num[num.size()/2]);
        vector<int> leftNum(num.begin(), num.begin()+num.size()/2);
        vector<int> rightNum(num.begin()+num.size()/2+1, num.end());
        root->left = sortedArrayToBST(leftNum);
        root->right = sortedArrayToBST(rightNum);
        return root;
    }
};
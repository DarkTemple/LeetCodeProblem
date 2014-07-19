/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root) {
            TreeLinkNode *left = root->left, *right = root->right;
            while (left && right) {
                left->next = right;
                left = left->right;
                right = right->left;
            }
            
            connect(root->left);
            connect(root->right);
        }
    }
};
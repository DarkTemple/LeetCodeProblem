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
        while (root) {
            TreeLinkNode *prev = NULL;
            TreeLinkNode *parent = root;
            root = NULL;
            while (parent) {
                if (!root) {
                	root = parent->left ? parent->left : parent->right;
                }

                if (parent->left) {
                    if (prev) {
                    	prev->next = parent->left;
                    }

                    prev = parent->left;
                }
                
                if (parent->right) {
                    if (prev) {
                    	prev->next = parent->right;
                    }
                    
                    prev = parent->right;
                }
                
                parent = parent->next;
            }
        }
    }
};
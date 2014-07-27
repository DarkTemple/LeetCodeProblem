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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> retContainer;
        vector<TreeNode *> assistStack;
        while (root || !assistStack.empty()) {
            while (root) {
                assistStack.push_back(root);
                root = root->left;
            }
            
            retContainer.push_back(assistStack.back()->val);
            root = assistStack.back()->right;
            assistStack.pop_back();
        }
        
        return retContainer;
    }
    
//    vector<int> inorderTraversal(TreeNode *root) {
//        vector<int> retContainer;
//        inorderHelper(root, retContainer);
//        return retContainer;
//    }
    
    void inorderHelper(TreeNode *root, vector<int> &retContainer) {
        if (root) {
            inorderHelper(root->left, retContainer);
            retContainer.push_back(root->val);
            inorderHelper(root->right, retContainer);
        }
    }
};

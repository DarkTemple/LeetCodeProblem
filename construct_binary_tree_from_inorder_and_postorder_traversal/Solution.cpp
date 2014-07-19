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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int len = inorder.size();
        if (len == 0) {
            return NULL;
        }
        
        int *arrInOrder = new int[len];
        int *arrPostOrder = new int[len];
        for (int i=0; i<len; i++) {
            arrInOrder[i] = inorder[i];
            arrPostOrder[i] = postorder[i];
        }
        
        return buildTreeHelper(arrInOrder, arrPostOrder, len);
    }
    
    TreeNode *buildTreeHelper(int *inorder, int *postorder, int len) {
        if (len == 0) {
            return NULL;
        }
        
        int rootVal = postorder[len-1];
        int rootInIndex = 0;
        for (; rootInIndex<len; rootInIndex++) {
            if (inorder[rootInIndex] == rootVal) {
                break;
            }
        }
        
        int *leftInOrder = inorder;
        int *rightInOrder = inorder + rootInIndex + 1;
        int leftLen = rootInIndex;
        int rightLen = len - leftLen - 1;
        
        int *leftPostOrder = postorder;
        int *rightPostOrder = postorder + leftLen;
        
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTreeHelper(leftInOrder, leftPostOrder, leftLen);
        root->right = buildTreeHelper(rightInOrder, rightPostOrder, rightLen);
        return root;
    }
};
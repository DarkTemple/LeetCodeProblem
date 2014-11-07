class Solution {
public:
    bool isLeafNode(TreeNode *node) {
        return node && !node->left && !node->right;
    }
    
    void sumNumbersHelper(TreeNode *node, int curPathNum, int &totalSum) {
        if (!node) return;
        
        curPathNum = (curPathNum * 10 + node->val);
        if (isLeafNode(node)) {
            totalSum += curPathNum;
        } else {
            sumNumbersHelper(node->left, curPathNum, totalSum);
            sumNumbersHelper(node->right, curPathNum, totalSum);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        int totalSum = 0;
        sumNumbersHelper(root, 0, totalSum);
        return totalSum;
    }
};
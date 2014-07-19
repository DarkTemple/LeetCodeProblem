class Solution {
public:
    void generateParenthesisHelper(vector<string> &ret, int left, int right, string parenthes, int n)
    {
        if (right == n) {
            ret.push_back(parenthes);
        } else {
            if (left < n) {
                // push left
                generateParenthesisHelper(ret, left+1, right, parenthes+"(", n);
            }
            
            if (left > right) {
                generateParenthesisHelper(ret, left, right+1, parenthes+")", n);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string parenthes;
        generateParenthesisHelper(ret, 0, 0, parenthes, n);
        return ret;
    }
};
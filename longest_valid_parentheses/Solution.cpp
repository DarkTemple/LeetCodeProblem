class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> lefts;
        int maxLen = 0;
        int last = -1;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                lefts.push_back(i);
            } else {
                if (lefts.empty()) {
                    last = i;
                } else {
                    lefts.pop_back();
                    if (lefts.empty()) {
                        maxLen = max(maxLen, i-last);
                    } else {
                        maxLen = max(maxLen, i-lefts.back());
                    }
                }
            }
        }

        return maxLen;
    }
};
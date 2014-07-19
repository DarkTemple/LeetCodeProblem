class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> numSet;
        int maxLen = 0;
        for (int i=0; i<num.size(); i++) {
            numSet.insert(num[i]);
        }

        for (int i=0; i<num.size(); i++) {
            if (numSet.find(num[i]) == numSet.end()) continue;
            int len = 1;
            int next = num[i] + 1;
            while (numSet.find(next) != numSet.end()) {
                len++;
                numSet.erase(next);
                next++;
            }

            int prev = num[i] - 1;
            while (numSet.find(prev) != numSet.end()) {
                len++;
                numSet.erase(prev);
                prev--;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
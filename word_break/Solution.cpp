typedef unordered_set<string>::iterator Iter;

class Solution {
public:
 bool wordBreakWithUnMatchSet(string s, unordered_set<string> &dict, unordered_set<string> &unmatchSet, int maxLen) {
        if (s.length() == 0) return true;

        for (int i=1; i<=min(maxLen, (int)s.length()); i++) {
            string prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end()) {
                string suffix = s.substr(i);
                if (unmatchSet.find(suffix) != unmatchSet.end()) {
                    continue;
                }
                
                if (wordBreakWithUnMatchSet(suffix, dict, unmatchSet, maxLen)) {
                    return true;
                }
            }
        }
        
        unmatchSet.insert(s);
        return false;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<string> unmatchSet;
        int maxLen = 0;
        for (Iter it = dict.begin(); it != dict.end(); it++) {
            maxLen = max(maxLen, (int)(*it).length());
        }
        
        return wordBreakWithUnMatchSet(s, dict, unmatchSet, maxLen);
    }
};
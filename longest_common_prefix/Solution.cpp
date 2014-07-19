class Solution {
public:
    string lcpOf2String(const string &s1, const string &s2) {
        int len = min((int)s1.length(), (int)s2.length());
        string lcp(len, 0);
        int i = 0;
        for (; i<min(s1.length(), s2.length()); i++) {
            if (s1[i] == s2[i]) {
                lcp[i] = s1[i];
            } else {
                break;
            }
        }
        
        return lcp.substr(0, i);
    }
    
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        string lcp = strs[0];
        for (int i=1; i<strs.size(); i++)
        {
            lcp = lcpOf2String(lcp, strs[i]);
        }
        
        return lcp;
    }
};
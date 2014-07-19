class Solution {
public:
    map<string, bool> dpTable;
    bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        string hashKey = s1 + " " + s2 + " " + s3;
        if (dpTable.find(hashKey) != dpTable.end()) {
            return dpTable[hashKey];
        }
        
        bool ret;
        if (s1.length() + s2.length() != s3.length()) {
            ret = false;
            goto RETURN;
        }
        
        if (s1.length() == 0) {
            ret = (s2 == s3);
            goto RETURN;
        } else {
            if (s1[0] == s3[0]) {
                ret = isInterleave(s1.substr(1), s2, s3.substr(1));
                if (ret) {
                    goto RETURN;
                }
            }
        }
        
        if (s2.length() == 0) {
            ret = (s1 == s3);
            goto RETURN;
        } else {
            if (s2[0] == s3[0]) {
                ret = isInterleave(s1, s2.substr(1), s3.substr(1));
                if (ret) {
                    goto RETURN;
                }
            }
        }
        
        ret = false;
        
    RETURN:
        dpTable[hashKey] = ret;
        return ret;
    }
};
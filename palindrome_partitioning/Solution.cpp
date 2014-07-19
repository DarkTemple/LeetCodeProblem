class Solution {
public:
    vector<vector<string>> partition(string s) {
        int strLen = (int)s.length();
        bool isPalTable[strLen][strLen];
        memset(isPalTable, false, sizeof(isPalTable));
        for (int i=0; i<strLen; i++) {
            for (int j=i; j>=0; j--) {
                if (s[j] == s[i] && (i-j<=1 || isPalTable[j+1][i-1])) {
                    isPalTable[j][i] = true;
                }
            }
        }
    
        vector<vector<string>> *dpTable = new vector<vector<string>>[strLen];
        for (int i=strLen-1; i>=0; i--) {
            vector<vector<string>> newRet;
            for (int j=i; j<strLen; j++) {
                if (isPalTable[i][j]) {
                    if (j == strLen-1) {
                        vector<string> subRet;
                        subRet.push_back(s.substr(i, j-i+1));
                        newRet.push_back(subRet);
                    } else {
                        vector<vector<string>> oldRet = dpTable[j+1];
                        for (int k=0; k<oldRet.size(); k++) {
                            vector<string> subRet = oldRet[k];
                            subRet.push_back(s.substr(i, j-i+1));
                            newRet.push_back(subRet);
                        }
                    }
                }
            }
            
            dpTable[i] = newRet;
        }
        
        for (int i=0; i<dpTable[0].size(); i++) {
            reverse(dpTable[0][i].begin(), dpTable[0][i].end());
        }
        
        reverse(dpTable[0].begin(), dpTable[0].end());
        return dpTable[0];
    }
};
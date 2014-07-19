class Solution {
public:
    string minWindow(string S, string T) {
        int charTable[256];
        memset(charTable, 0, sizeof(charTable));
        for (int i=0; i<T.length(); i++) {
            charTable[T[i]]++;
        }
        
        int curTable[256];
        memset(curTable, 0, sizeof(curTable));
        int i=0, j=0, count=0, minLen=INT_MAX;
        string ret = "";
        for (; i<S.length(); i++) {
            if (charTable[S[i]] > 0) {
                curTable[S[i]]++;
                if (curTable[S[i]] <= charTable[S[i]]) {
                    count++;
                    if (count == T.length()) {
                        for (; j<=i; j++) {
                            if (curTable[S[j]] > 0) {
                                curTable[S[j]]--;
                                if (curTable[S[j]] < charTable[S[j]]) {
                                    count--;
                                    if (i-j+1 < minLen) {
                                        minLen = i-j+1;
                                        ret = S.substr(j, minLen);
                                    }
                                    
                                    j++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return ret;
    }
};
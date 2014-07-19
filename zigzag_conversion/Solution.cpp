class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        int T = 2*nRows-2;
        string ret;
        for (int i=0; i<nRows; i++) {
            int j = i;
            while (j < s.length()) {
                ret.append(1, s[j]);
                if (i > 0 && i < nRows-1) {
                    int k = j + T - 2 * i;
                    if (k < s.length()) {
                        ret.append(1, s[k]);
                    }
                }
                
                j += T;
            }
        }
        
        return ret;
    }
};
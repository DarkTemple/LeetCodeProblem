class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = (int)a.length(), lenB = (int)b.length();
        int retLen = max(lenA, lenB) + 1;
        string ret(retLen, 0);
        int c = 0;
        for (int i=1, j=retLen; i<=retLen; i++) {
            int numA = i > lenA ? 0 : (a[lenA-i] - '0');
            int numB = i > lenB ? 0 : (b[lenB-i] - '0');
            int tmp = numA + numB + c;
            ret[--j] = (tmp % 2) + '0';
            c = tmp / 2;
        }
        
        if (ret[0] == '0') ret = ret.substr(1, retLen-1);
        return ret;
    }
};
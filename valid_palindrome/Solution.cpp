class Solution {
public:
    bool isValidChar(char &c) {
        if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9')) return true;
        if ('A' <= c && c <= 'Z') {
            c += 32;
            return true;
        }
        
        return false;
    }
    
    bool isPalindrome(string s) {
        int i=0, j=0;
        for (; j<s.length(); j++) {
            if (isValidChar(s[j])) {
                s[i++] = s[j];
            }
        }
        
        s = s.substr(0, i);
        int len = (int)s.length();
        i = (len-1)/2;
        j = len % 2 == 1 ? i : i+1;
        while (i >= 0) {
            if (s[i] != s[j]) return false;
            i--; j++;
        }
        
        return true;
    }
};
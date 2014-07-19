class Solution {
public:
    bool isNumber(const char *s) {
        // strip blank
        char *str = new char[strlen(s)+1];
        strcpy(str, s);
        while (*str == ' ') str++;
        for (int i=(int)strlen(str)-1; i>=0; i--) {
            if (str[i] == ' ') str[i] = '\0';
            else break;
        }
        
        bool preDot = false, preE = false, hasDot = false, hasE = false,
        preSym = false, firstChar = true;
        while (*str) {
            if (*str == '.') {
                if (hasDot || hasE) return false;
                preDot = true;
                hasDot = true;
            } else if (*str == '+' || *str == '-') {
                if (!firstChar || preSym || preDot) return false;
                preSym = true;
            } else if (*str == 'e') {
                if (hasE || preSym || firstChar) return false;
                preE = true;
                hasE = true;
                preDot = false;
                firstChar = true;
            } else if (*str <= '9' && *str >= '0') {
                preDot = false;
                preE = false;
                preSym = false;
                firstChar = false;
            } else {
                return false;
            }
            
            str++;
        }
        
        return ((preDot && !firstChar) || !preDot) && !preE && !preSym && !firstChar;
    }
};
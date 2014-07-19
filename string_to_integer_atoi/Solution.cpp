class Solution {
public:
    int atoi(const char *str) {
        while (*str == ' ') str++;
        int len = strlen(str);
        for (int i=strlen(str)-1; i>=0; i--) {
            if (str[i] == ' ') len--;
        }
        
        int sym = 1;
        long long ret = 0;
        for (int i=0; i<len; i++) {
            if (i == 0 && (str[i] == '+' || str[i] == '-')) {
                sym = str[i] == '+' ? 1 : -1;
            } else if (str[i] >= '0' && str[i] <= '9') {
                ret = ret * 10 + str[i] - '0';
                if (ret > INT_MAX) break;
            } else {
                break;
            }
        }
        
        if (ret > INT_MAX) {
            if (sym == 1) return INT_MAX;
            else if (sym == -1 && ret > (long long)INT_MAX+1) return INT_MIN;
        }
        
        return sym * (int)ret;
    }
};
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
	    if (!s || !p) return false;
	    if (!*p) return !*s;
	    if (*(p+1) == '*') {
	        while (*s && *p == '.' || *s == *p) {
	            bool ret = isMatch(s++, p+2);
	            if (ret) return true;
	        }
	        
	        return isMatch(s, p+2);
	    } else if (*s && *p == '.' || *s == *p) {
            return isMatch(s+1, p+1);	        
	    } else {
	        return false;
	    }
	}
};
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int hayLen = (int)strlen(haystack);
        int needLen = (int)strlen(needle);
        int i=needLen-1, j=needLen-1;
        int skipTable[256];
        memset(skipTable, -1, sizeof(skipTable));
        for (int i=0; i<needLen-1; i++) {
            skipTable[needle[i]] = i;
        }
        
        while (i < hayLen && j >= 0) {
            if (haystack[i] == needle[j]) {
                i--; j--;
            } else {
                i += needLen - j - 1;
                char badChar = haystack[i];
                int skipLen = skipTable[badChar];
                if (skipLen == -1) {
                    i += needLen;
                } else {
                    i += needLen - skipLen - 1;
                }
                
                j = needLen - 1;
            }
        }
        
        if (j < 0) return haystack + i + 1;
        return NULL;
    }
};
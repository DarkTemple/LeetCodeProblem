class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        unsigned int reverseNum = 0;
        unsigned int originNum = x;
        while (originNum) {
            reverseNum = reverseNum * 10 + (originNum % 10);
            originNum /= 10;
        }
        
        return x == reverseNum;
    }
};

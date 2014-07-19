class Solution {
public:
    int reverse(int x) {
        int input = (long long)x;
        int flag = 1;
        if (input < 0) {
            flag = -1;
            input = -input;
        }
        
        int output = 0;
        while (input > 0) {
            output = output * 10 + input % 10;
            input /= 10;
        }
        
        return output * flag;
    }
};
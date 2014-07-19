class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        bool isNeg = (dividend < 0 ) ^ (divisor < 0);
        long long a = abs((long long)dividend);  
        long long b = abs((long long)divisor); 
        
        int ret = 0;
        while (a >= b) {
            long long i = 1, d = b;
            while (a >= (d << 1)) {
                d <<= 1;
                i <<= 1;
            }
            
            a -= d;
            ret += i;
        }
        
        return isNeg ? -1 * ret : ret;
    }
};
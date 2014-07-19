class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        int sym = 1;
        if (n < 0) {
            sym = -1;
            n = -n;
        }
        
        double a = pow(x, n/2);
        double ret = (n % 2) ? a*a*x : a*a;
        return sym == -1 ? 1/ret : ret;
    }
};
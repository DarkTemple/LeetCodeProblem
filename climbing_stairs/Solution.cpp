class Solution {
public:
    int climbStairs(int n) {
        int fn_1 = 1, fn_2 = 1;
        for (int i=2; i<=n; i++) {
            int tmp = fn_1;
            fn_1 += fn_2;
            fn_2 = tmp;
        }
        
        return fn_1;
    }
};
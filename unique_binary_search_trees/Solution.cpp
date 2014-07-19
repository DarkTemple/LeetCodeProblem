class Solution {
public:
    int numTrees(int n) {
        int catalan[100];
        catalan[0] = 1, catalan[1] = 1;
        for (int i=2; i<=n; i++) {
            int sum = 0;
            for (int j=0; j<=(i-1)/2; j++) {
                sum += (catalan[j] * catalan[i-1-j]) * ((j == (i-1)/2 && i % 2) ? 1 : 2);
            }

            catalan[i] = sum;
        }

        return catalan[n];
    }
};
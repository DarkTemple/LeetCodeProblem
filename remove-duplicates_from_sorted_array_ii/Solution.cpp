class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        bool isDup = false;
        int i=0, j=i+1;
        for (; j<n; j++) {
            if (A[i] != A[j]) {
                A[++i] = A[j];
                isDup = false;
            } else {
                if (!isDup) {
                    A[++i] = A[j];
                    isDup = true;
                }
            }
        }
        
        return i+1;
    }
};
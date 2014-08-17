class Solution {
public:
    void sortColors(int A[], int n) {
        int i = -1, j = n, k = 0;
        while (k < j) {
            if (A[k] == 0) {
                swap(A[++i], A[k++]);
            } else if (A[k] == 1) {
                k++;
            } else {
                swap(A[--j], A[k]);
            }
        }
    }
};
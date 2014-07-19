class Solution {
public:
    int trap(int A[], int n) {
        int leftHeight[n], rightHeight[n];
        for (int i=0; i<n; i++) {
            leftHeight[i] = i == 0 ? A[i] : max(leftHeight[i-1], A[i]);
        }

        int sum = 0, maxHeight = 0;
        for (int i=n-1; i>=0; i--) {
            maxHeight = max(maxHeight, A[i]);
            sum += min(leftHeight[i], maxHeight) - A[i];
        }

        return sum;
    }
};
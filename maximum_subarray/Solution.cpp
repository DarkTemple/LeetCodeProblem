class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = INT_MIN, contMaxSum = INT_MIN;
        for (int i=0; i<n; i++) {
            contMaxSum = contMaxSum > 0 ? contMaxSum+A[i] : A[i];
            maxSum = max(maxSum, contMaxSum);
        }
        
        return maxSum;
    }
};
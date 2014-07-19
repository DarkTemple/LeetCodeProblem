class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
        while (j < n) {
            if (A[j] != elem) {
                A[i++] = A[j];
            }
            
            j++;
        }
        
        return i;
    }
};
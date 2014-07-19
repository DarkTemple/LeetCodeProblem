class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int start = 0;
        int end = n - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;                
            }
        }
        
        return start;
    }
};
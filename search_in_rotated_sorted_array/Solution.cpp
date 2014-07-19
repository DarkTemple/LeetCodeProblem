class Solution {
public:
    int search(int A[], int n, int target) {
		int start = 0, end = n-1, mid;
		while (start <= end) {
			mid = start + (end - start)/2;
			if (A[mid] == target)  {
				return mid;
			} else if (A[start] <= A[mid]) {
				if (A[start] <= target && target < A[mid]) {
					end = mid - 1;
				} else {
					start = mid + 1;
				}
			} else {
				if (A[mid] < target && target <= A[end]) {
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			}
		}
		
		return -1;
    }
};
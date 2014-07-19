class Solution {
public:
    int searchLeft(int A[], int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) end = mid - 1;
            else start = mid + 1;
        }
        
        return end + 1;
    }
    
    int searchRight(int A[], int start, int end, int target) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] <= target) start = mid + 1;
            else end = mid - 1;
        }
        
        return start - 1;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                // search left and right
                int left = searchLeft(A, start, mid, target);
                int right = searchRight(A, mid, end, target);
                vector<int> range;
                range.push_back(left);
                range.push_back(right);
                return range;
            } else if (A[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return vector<int>(2, -1);
    }
};
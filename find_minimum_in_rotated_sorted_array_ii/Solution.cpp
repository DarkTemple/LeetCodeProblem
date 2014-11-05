class Solution {
public:
    int findMinInRotatedArr(vector<int> &num, int start, int end) {
        if (start == end) return num[start];
        int mid = (start + end) / 2;
        if (num[start] < num[end]) {
            return num[start];
        } else if (num[start] == num[end]) {
            if (num[mid] < num[start]) {
                return findMinInRotatedArr(num, start+1, mid);
            } else if (num[mid] > num[start]) {
                return findMinInRotatedArr(num, mid+1, end);
            } else {
                return findMinInRotatedArr(num, start+1, end);
            }
        } else {
            if (num[mid] < num[start]) {
                return findMinInRotatedArr(num, start+1, mid);
            } else {
                return findMinInRotatedArr(num, mid+1, end);
            }
        }
    }
    
    int findMin(vector<int> &num) {
        return findMinInRotatedArr(num, 0, (int)num.size()-1);
    }
};
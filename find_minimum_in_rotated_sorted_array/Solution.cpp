class Solution {
public:
    int findMinInRotatedArr(vector<int> &num, int start, int end) {
        if (start == end) return num[start];
        int mid = (start + end) / 2;
        if (num[start] <= num[mid]) {
            return num[start] < num[end] ? num[start] : findMinInRotatedArr(num, mid+1, end);
        } else {
            return findMinInRotatedArr(num, start, mid);
        }
    }
    
    int findMin(vector<int> &num) {
        return findMinInRotatedArr(num, 0, (int)num.size()-1);
    }
};
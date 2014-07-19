class Solution {
public:
    int find2SumCloset(vector<int> &num, int invalidIdx, int target) {
        int i = 0, j = num.size()-1, minDelta = 1 << 30;
        while (i < j) {
            if (i == invalidIdx) {i++; continue;}
            if (j == invalidIdx) {j--; continue;}
            int sum = num[i] + num[j];
            if (abs(sum-target) < abs(minDelta)) minDelta = sum-target;

            if (sum == target) {
                return target;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return target + minDelta;
    }

    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int minDelta = 1 << 30;
        for (int i=0; i<num.size(); i++) {
            int sum = num[i] + find2SumCloset(num, i, target-num[i]);
            if (abs(sum - target) < abs(minDelta)) minDelta = sum - target;
        }

        return minDelta + target;
    }
};
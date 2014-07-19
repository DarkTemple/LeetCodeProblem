class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = num.size();
        int i = size-2;
        for (; i>=0; i--) {
            if (num[i] < num[i+1]) {
                break;
            }
        }
        
        if (i < 0) {
            // the last permuration
            reverse(num.begin(), num.end());
        } else {
            int j = size - 1;
            for (; j>i; j--) {
                if (num[j] > num[i]) {
                    break;                    
                }
            }
            
            swap(num[i], num[j]);
            reverse(num.begin()+i+1, num.end());
        }
    }
};
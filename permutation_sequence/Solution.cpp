class Solution {
public:
    int fact(int n) {
        int ret = 1;
        while (n > 0) ret *= n--;
        return ret;
    }

    void kthPerm(vector<int> &nums, string &perm, int k) {
        int n = nums.size();
        if (n == 0) return;
        int f = fact(n-1);
        int index = (k-1) / f;
        int num = nums[index];
        perm.push_back('0'+num);
        nums.erase(nums.begin()+index);
        k -= index * f;
        kthPerm(nums, perm, k);
    }

    string getPermutation(int n, int k) {
        string ret;
        int f = fact(n);
        if (k > f || k <= 0) return ret;
        vector<int> nums;
        for (int i=1; i<=n; i++) nums.push_back(i);
        kthPerm(nums, ret, k);
        return ret;
    }
};
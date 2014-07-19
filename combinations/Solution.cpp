class Solution {
public:
    void combineHelper(vector<vector<int> > &ret, vector<int> &path, int begin, int n, int k) {
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        
        // 这一句必须要加，可以减少不必要的迭代次数
        if (n-begin+1 < k - path.size()) return;
        
        for (int i=begin; i<=n; i++) {
            path.push_back(i);
            combineHelper(ret, path, i+1, n, k);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> path;
        combineHelper(ret, path, 1, n, k);
        return ret;
    }
};
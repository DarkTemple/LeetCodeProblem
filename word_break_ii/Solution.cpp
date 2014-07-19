class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = (int)s.size();
        vector<vector<vector<string>>> dp(n + 1);
        dp[0].push_back(vector<string>());
        size_t max_len = 0;
        
        vector<bool> buffer(256, false);
        
        for (auto &str : dict) {
            for (auto &c : str)
                buffer[c] = true;
        }
        
        for (auto &c : s) {
            if (!buffer[c])
                return vector<string>();
        }
        
        for (auto &str : dict) {
            max_len = max(max_len, str.size());
        }
        
        for (int i = 0; i < n; i++) {
            for (int len = 1; i + len - 1 < n && len <= max_len; len++) {
                string t = s.substr(i, len);
                if (dict.count(t) > 0) {
                    for (auto vs : dp[i]) {
                        vs.push_back(t);
                        dp[i+len].push_back(vs);
                    }
                }
            }
        } 
        
        vector<string> res;
        for (auto &vs : dp[n]) {
            string t;
            for (size_t i = 0; i < vs.size(); i++) {
                if (i == 0)
                    t += vs[i];
                else
                    t += " " + vs[i];
            }

            res.push_back(t);
        }
        
        return res;
    }
};
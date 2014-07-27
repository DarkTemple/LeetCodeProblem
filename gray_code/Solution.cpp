class Solution {
public:
    static inline int reverstBit(int x, int n) {
        return x^(1 << n);
    }
    
    vector<int> grayCode(int n) {
        vector<int> ret;
        set<int> hashSet;
        int lastCode = 0;
        ret.push_back(lastCode);
        hashSet.insert(lastCode);

        while (ret.size() != (1<<n)) {
            for (int i=0; i<n; i++) {
                int newCode = reverstBit(lastCode, i);
                if (hashSet.find(newCode) == hashSet.end()) {
                    hashSet.insert(newCode);
                    ret.push_back(newCode);
                    lastCode = newCode;
                    break;
                }
            }
        }
        
        return ret;
    }
};
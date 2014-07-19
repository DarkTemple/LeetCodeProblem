class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        map<string, int> hashMap;
        for (int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (hashMap.count(str) == 0) {
                hashMap[str] = i;
            } else {
                if (hashMap[str] != -1) {
                    int index = hashMap[str];
                    ret.push_back(strs[index]);
                    hashMap[str] = -1;
                }
                
                ret.push_back(strs[i]);
            }
        }
        
        return ret;
    }
};
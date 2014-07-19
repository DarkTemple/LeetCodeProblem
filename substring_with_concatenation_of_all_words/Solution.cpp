class Solution {
public:
    bool checkValidStr(string &s, int start, int n, int m,
                       map<string, int> &recMap) {
        for (int i=0; i<n; i++) {
            string subS = s.substr(start+i*m, m);
            if (recMap.find(subS) == recMap.end()) {
                return false;
            } else {
                if (recMap[subS] == 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void initRecMap(vector<string> &L, map<string, int> &recMap) {
        recMap.clear();
        for (int i=0; i<L.size(); i++) {
            string key = L[i];
            recMap[key]++;
        }
    }
    
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> idxes;
        int n = L.size();
        int m = L[0].length();
        int len = n*m;
        
        map<string, int> recMap;
        map<string, int> tmpMap;
        initRecMap(L, recMap);
        
        for (int i=0; i<=(int)S.length()-len; i++) {
            int j = 0;
            tmpMap.clear();
            for (; j<n; j++) {
                string subStr = S.substr(i+j*m, m);
                if (recMap.find(subStr) == recMap.end()) {
                    break;
                } else {
                    tmpMap[subStr]++;
                    if (tmpMap[subStr] > recMap[subStr]) {
                        break;
                    }
                }
            }
            
            if (j == n) {
                idxes.push_back(i);
            }
        }
        
        return idxes;
    }
};
class Solution {
public:
    bool isEditDis1(const string &a, const string &b) {
        if (a.length() != b.length()) return false;
        int diff = 0;
        for (int i=0; i<a.length(); i++) {
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        
        return (diff == 1);
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q1;
        queue<string> q2;
        q1.push(start);
        int minLength = 2;
        while (!q1.empty()) {
            while (!q1.empty()) {
                string cur = q1.front();
                q1.pop();
                if (isEditDis1(cur, end)) {
                    return minLength;
                }

                for (int i=0; i<cur.length(); i++) {
                    for (int j='a'; j<='z'; j++) {
                        if (cur[i] == j) {
                            continue;
                        }

                        string neighborStr(cur);
                        neighborStr[i] = j;
                        if (dict.count(neighborStr) > 0) {
                            q2.push(neighborStr);
                            dict.erase(neighborStr);
                        }
                    }
                }
            }
            
            minLength++;
            q1.swap(q2);
        }
        
        return 0;
    }
};
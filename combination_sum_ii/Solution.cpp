class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        set<vector<int> > *dpTable = new set<vector<int> > [target+1];
        set<vector<int> > s; s.insert(vector<int>()); dpTable[0] = s;
        for (int i=0; i<num.size(); i++) {
            for (int j=target; j>= num[i]; j--) {
                set<vector<int> > combSet = dpTable[j-num[i]];
                if (combSet.size() > 0) {
                    set<vector<int> > newCombSet;
                    if (dpTable[j].size() > 0) newCombSet = dpTable[j];
                    
                    for (set<vector<int> >::iterator it = combSet.begin(); it != combSet.end(); it++) {
                        vector<int> comb = *it;
                        comb.push_back(num[i]);
                        sort(comb.begin(), comb.end());
                        newCombSet.insert(comb);
                    }
                    
                    dpTable[j] = newCombSet;
                }
            }
        }
        
        vector<vector<int> > ret;
        for (set<vector<int> >::iterator it = dpTable[target].begin(); it != dpTable[target].end(); it++) {
            ret.push_back(*it);
        }
        
        delete [] dpTable;
        return ret;
    }
};
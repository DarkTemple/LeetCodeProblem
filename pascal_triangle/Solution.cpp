class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows >= 1) {
            ret.push_back(vector<int>(1, 1));
        }
        
        for (int i=1; i<numRows; i++) {
            vector<int> upVec = ret.back();
            vector<int> curVec;
            for (int j=-1; j<(int)upVec.size(); j++) {
                curVec.push_back((j>=0 ? upVec[j] : 0) + (j+1<upVec.size() ? upVec[j+1] : 0));
            }
            
            ret.push_back(curVec);
        }
        
        return ret;
    }
};
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int retNum = 0;
        int curCount = 0;
        for (int i=0; i<num.size(); i++) {
            if (curCount == 0) {
                retNum = num[i];
                curCount++;
            } else {
                if (num[i] == retNum) {
                    curCount++;
                } else {
                    curCount--;
                }
            }
        }
        
        return retNum;
    }
};
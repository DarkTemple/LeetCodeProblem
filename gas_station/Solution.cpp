class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int totalSum = 0, subSum = 0;
        int begin = 0;
        for (int i=0; i<gas.size(); i++) {
            totalSum += gas[i] - cost[i];
            subSum += gas[i] - cost[i];
            if (subSum < 0) {
                begin = i+1;
                subSum = 0;
            }
        }
        
        return totalSum >= 0 ? begin : -1;
    }
};
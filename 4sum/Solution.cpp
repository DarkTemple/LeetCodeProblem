class Solution {
public:
void printVec(vector<int> v) {
    for (int i=0; i<v.size(); i++)
        cout << v[i] << endl;
}

    vector<vector<int> > findZeroSumInSortedArr(vector<int> &num, int begin, int count, int target) {
        vector<vector<int> > ret;
        vector<int> tuple;
        set<int> visited;
        if (count == 2) {
            int i = begin, j = num.size()-1;
            while (i < j) {
                int sum = num[i] + num[j];
                if (sum == target && visited.find(num[i]) == visited.end()) {
                    tuple.clear();
                    visited.insert(num[i]);
                    visited.insert(num[j]);
                    tuple.push_back(num[i]);
                    tuple.push_back(num[j]);
                    ret.push_back(tuple);
                    i++; j--;
                } else if (sum < target) {
                    i++;
                } else {
                    j--;
                }
            }
        } else {
            for (int i=begin; i<num.size(); i++) {
                if (visited.find(num[i]) == visited.end()) {
                    visited.insert(num[i]);
                    vector<vector<int> > subRet = findZeroSumInSortedArr(num, i+1, count-1, target-num[i]);
                    if (!subRet.empty()) {
                        for (int j=0; j<subRet.size(); j++) {
                            subRet[j].insert(subRet[j].begin(), num[i]);
                        }

                        ret.insert(ret.end(), subRet.begin(), subRet.end());
                    }
                }
            }
        }

        return ret;
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        return findZeroSumInSortedArr(num, 0, 3, 0);
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        return findZeroSumInSortedArr(num, 0, 4, target);
    }
};
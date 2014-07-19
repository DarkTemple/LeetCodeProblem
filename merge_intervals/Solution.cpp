/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 bool cmp(Interval a, Interval b) {
    return (a.start < b.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur;
        for (int i=0; i<intervals.size(); i++) {
            if (i == 0) {
                cur = intervals[0];
                continue;
            }
            
            if (cur.end < intervals[i].start) {
                ret.push_back(cur);
                cur = intervals[i];
            } else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        
        ret.push_back(cur);
        return ret;
    }
};

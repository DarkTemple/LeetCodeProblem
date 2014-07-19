class Solution {
public:
    int maxPoints(vector<Point> &points) {
        map<double, int> slopeMap;
        int maxNum = 0;
        for (int i=0; i<points.size(); i++) {
            Point a = points[i], b;
            int samePointNum = 1;
            int maxSlopePoint = 0;
            slopeMap.clear();
            for (int j=+1; j<points.size() && i!=j; j++) {
                b = points[j];
                double slope;
                if (a.x == b.x) {
                    if (a.y == b.y) {
                        samePointNum++;
                        continue;
                    }
                    
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = double(a.y - b.y) / (a.x - b.x);
                }
                
                slopeMap[slope]++;
                maxSlopePoint = max(maxSlopePoint, slopeMap[slope]);
            }
            
            maxNum = max(maxNum, samePointNum+maxSlopePoint);
        }
        
        return maxNum;
    }
};
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxRet = 0;
        for (int i=0; i<n; i++) {
            minPrice = min(minPrice, prices[i]);
            maxRet = max(maxRet, prices[i]-minPrice);
        }
        
        return maxRet;
    }
};
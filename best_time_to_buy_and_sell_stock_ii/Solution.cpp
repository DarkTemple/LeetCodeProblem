class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int sumProfit = 0;
        int begin = 0, end = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] <= prices[i-1]) {
                end = i-1;
                sumProfit += prices[end] - prices[begin];
                begin = i;
            }
        }
        
        if (begin < prices.size()) {
            sumProfit += prices.back() - prices[begin];
        }
        
        return sumProfit;
    }
};
class Solution {
public:
    int candy(vector<int> &ratings) {
        int candyArr[ratings.size()];
        for (int i=0; i<ratings.size(); i++) {
            candyArr[i] = 1;
        }

        for (int i=1; i<ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) candyArr[i] = candyArr[i-1] + 1;
        }

        for (int i=ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1] && candyArr[i] <= candyArr[i+1]) candyArr[i] = candyArr[i+1] + 1;
        }

        int sum = 0;
        for (int i=0; i<ratings.size(); i++) {
            sum += candyArr[i];
        }
        
        return sum;
    }
};
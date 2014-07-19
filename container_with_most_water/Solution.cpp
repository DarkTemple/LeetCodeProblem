class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxWater = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            else if (height[i] > height[j])j--;
            else {i++; j--;}
        }
        
        return maxWater;
    }
};

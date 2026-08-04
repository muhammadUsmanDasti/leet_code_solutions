class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int width = height.size() - 1;
        int max = 0;
        while(i < j) {
            int currentNet = 0;
            if(height[i] <= height[j]) {
                currentNet = height[i] * width;
                i++;
            }
            else {
                currentNet = height[j] * width;
                j--;
            }
            if(currentNet > max) {
                max = currentNet;
            }
            width--;
        }
        return max;
    }
};
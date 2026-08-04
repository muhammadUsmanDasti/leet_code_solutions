class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int width = height.size() - 1;
        int maxNet = 0;
        while(i < j) {
            if(height[i] <= height[j]) {
                int currentNet = height[i] * width;
                if(currentNet > maxNet) {
                    maxNet = currentNet;
                }
                i++;
            }
            else {
                int currentNet = height[j] * width;
                if(currentNet > maxNet) {
                    maxNet = currentNet;
                }
                j--;
            }
            width--;
        }
        return maxNet;
    }
};
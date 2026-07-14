class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int width = height.size() - 1;
        int max = 0;
        while(i <= j) {
            int netMax = 0;
            if(height[i] >= height[j]) {
                netMax = height[j] * width;
                j--;
            }
            else {
                netMax = height[i] * width;
                i++;
            }

            if(netMax >= max) {
                max = netMax;
            }
            width--;
        }
        return max;
    }
};
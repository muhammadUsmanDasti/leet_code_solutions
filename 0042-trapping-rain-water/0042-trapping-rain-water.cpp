class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int leftMax = height[L];
        int rightMax = height[R];
        int trappedWater = 0;
        while(L < R) {
            if(leftMax <= rightMax) {
                int waterUnits = leftMax - height[L];
                if(waterUnits >= 0) {
                    trappedWater += waterUnits;
                }
                L++;
                if(height[L] > leftMax) {
                    leftMax = height[L];
                }
            }
            else {
                int waterUnits = rightMax - height[R];
                if(waterUnits >= 0) {
                    trappedWater += waterUnits;
                }
                
                R--;
                if(height[R] > rightMax) {
                    rightMax = height[R];
                }
            }
        }
        return trappedWater;
    }
};
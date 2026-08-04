class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int leftMax = height[L];
        int rightMax = height[R];
        int res = 0;
        while(L < R) {
            leftMax = max(leftMax, height[L]);
            rightMax = max(rightMax, height[R]);
            if(leftMax <= rightMax) {
                res += leftMax - height[L];
                L++;
            }
            else {
                res += rightMax - height[R];
                R--;
            }
        }
        return res;
    }
};
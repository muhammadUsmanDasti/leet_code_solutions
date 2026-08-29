class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> stack;
        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++) {     
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                int height = heights[stack.back()];
                stack.pop_back();
                int width = (stack.empty()) ? i : i - stack.back() -1;
                int area = height * width;
                largestArea = max(largestArea, area);
            }
            stack.push_back(i);  
        }
        for (int i = 0; i < stack.size(); i++) {
            int leftBound = (i == 0) ? -1 : stack[i-1];
            int width = heights.size() - leftBound - 1;
            int area = heights[stack[i]] * width;
            
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};
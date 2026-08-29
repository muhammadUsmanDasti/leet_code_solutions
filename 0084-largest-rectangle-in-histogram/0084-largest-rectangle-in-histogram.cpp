class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> stack;
        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++) {     
            while (!stack.empty() && stack.back().second > heights[i]) {
                int height = stack.back().second;
                stack.pop_back();
                int width = (stack.empty()) ? i : i - stack.back().first -1;
                int area = height * width;
                largestArea = max(largestArea, area);
            }
            stack.push_back({i, heights[i]});  
        }
        for (int i = 0; i < stack.size(); i++) {
            int leftBound = (i == 0) ? -1 : stack[i-1].first;
            int width = heights.size() - leftBound - 1;
            int area = stack[i].second * width;
            
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};
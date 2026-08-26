class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(),0);
        vector<pair<int,int>> stack;
        for (int i = 0; i < temperatures.size(); i++) {
            if (stack.empty()) {
                stack.push_back({temperatures[i], i});
            } else if(stack.back().first >= temperatures[i]) {
                stack.push_back({temperatures[i], i});
            }
            bool flag = false;
            while (!(stack.empty()) && stack.back().first < temperatures[i]) {
                answer[stack.back().second] = i - stack.back().second;
                stack.pop_back();
                flag = true;
            }
            if(flag) {
                stack.push_back({temperatures[i], i});
            }
            
        }
        return answer;
    }
};
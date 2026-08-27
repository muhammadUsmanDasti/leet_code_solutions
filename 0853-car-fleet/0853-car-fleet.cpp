class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        vector<double> stack;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });
        for(int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if(stack.empty() || time > stack.back()){

                stack.push_back(time);
            }
        }
        return stack.size();
    }
};
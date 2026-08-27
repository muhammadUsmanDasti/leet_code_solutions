class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> arr;
        vector<pair<int, int>> stack;
        for (int i = 0; i < position.size(); i++) {
            arr.push_back({position[i], speed[i]});
        }
        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });
        int noOfFleets = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(!stack.empty() && stack.back().second < arr[i].second){
                float first = static_cast<float>(static_cast<float>(target - stack.back().first)) / stack.back().second;
                float second = static_cast<float>(static_cast<float>(target - arr[i].first)) / arr[i].second;
                if (second > first) {
                    stack.push_back(arr[i]);
                    noOfFleets++;
                }
            }
            else {
                stack.push_back(arr[i]);
                noOfFleets++;
            }
        }
        return noOfFleets;
    }
};
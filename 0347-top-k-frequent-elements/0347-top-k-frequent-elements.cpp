class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, pair<int, bool>> hashTable;
        for(int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            hashTable[key].first++;
            hashTable[key].second = false;
        }

        vector<int> result;
        int max = hashTable[nums[0]].first;
        int maxKey;
        int z = 0;
        while(z < k) {
            for(const auto& [key,state] : hashTable) {
                if(max <= state.first && state.second == false) {
                    max = state.first;
                    maxKey = key;
                }
            }
            result.push_back(maxKey);
            hashTable[maxKey].second = true;
            max = INT_MIN;
            z++;
        }
        return result;
    }
};
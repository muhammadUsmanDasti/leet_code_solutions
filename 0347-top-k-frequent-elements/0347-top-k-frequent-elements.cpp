class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int,pair<int, bool>>> frequencyCountTable;
        int count = 0;
        int number = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == number) {
                count++;
            }
            else {
                frequencyCountTable.push_back({number, {count, false}});
                count = 1;
                number = nums[i];
            }
        }
        frequencyCountTable.push_back({number, {count, false}});
        vector<int> result;
        int max = frequencyCountTable[0].second.first;
        int loopCount = 0;
        int z = 0;
        while(z < k) {
            for(int j = 0; j < frequencyCountTable.size(); j++) {
                if(max <= frequencyCountTable[j].second.first && frequencyCountTable[j].second.second == false) {
                    max = frequencyCountTable[j].second.first;
                    loopCount = j;
                }
            }
            result.push_back(frequencyCountTable[loopCount].first);
            frequencyCountTable[loopCount].second.second = true;
            max = INT_MIN;
            z++;
        }
        return result;
    }
};
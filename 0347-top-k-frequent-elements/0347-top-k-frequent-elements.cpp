class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            hashTable[key]++;
        }
        vector<vector<int>> bucketList(nums.size() + 1);
        for(const auto& [key,count] : hashTable) {
            bucketList[count].push_back(key);
        }
        vector<int> result;
        for(int j = bucketList.size()-1; result.size() != k; j--) {
            if(bucketList[j].empty()){
                continue;
            }
            for(int num : bucketList[j]) {
                if(result.size() != k){
                    result.push_back(num);
                }
                
            }

        }
        
        return result;
    }
};
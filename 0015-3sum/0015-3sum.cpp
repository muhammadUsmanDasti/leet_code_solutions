class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) {
                if(nums[i] == nums[i - 1]){
                    continue;
                }
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                long sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    result.push_back(triplet);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                        continue;
                    }
                    while(j < k && nums[k] == nums[k + 1]) {
                        k--;
                        continue;
                    }
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    j++;
                }

            }
            
        }
        return result;
    }
};
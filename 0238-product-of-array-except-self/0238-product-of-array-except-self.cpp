class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);
        int last_suffix = 1;
        int final_suffix = 1;
        for(int i = 1; i < n; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        for(int i = n-2; i >= 0; i--) {

            final_suffix = (last_suffix * nums[i+1]);
            result[i] *= final_suffix;
            last_suffix = final_suffix;
        }
        return result;
    }
};
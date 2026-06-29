class Solution {
public:
    int findMin(vector<int>& nums){
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % size;
            int previous = (mid + size -1) % size;
            if(nums[low] < nums[high]){
                return nums[low];
            }
            else if(nums[mid] <= nums[next] && nums[mid] <= nums[previous]){
                return nums[mid];
            }
            else if(nums[mid] <= nums[high]){
                high = mid - 1;
            }
            else if(nums[mid] >= nums[low]){
                low = mid + 1;
            }
        }
        return -2100000;
    }
};
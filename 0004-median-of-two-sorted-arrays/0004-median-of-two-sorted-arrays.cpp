class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int j = 0, k = 0;
        vector<int> nums3;
        while(j < nums1.size() && k < nums2.size()){
            if(nums1[j] <= nums2[k]) {
                nums3.push_back(nums1[j]);
                j++;
            }
            else if(nums1[j] >= nums2[k]) {
                nums3.push_back(nums2[k]);
                k++;
            }
        }
        while(j < nums1.size()){
            nums3.push_back(nums1[j]);
            j++;
        }
        while(k < nums2.size()){
            nums3.push_back(nums2[k]);
            k++;
        }
        return nums3;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3 = merge(nums1,nums2);
        int n = nums3.size();
        double median = 0;
        if(nums3.size() % 2 == 0){
            median = ( nums3[n / 2] + nums3[(n / 2) - 1] ) / 2.0;
        }
        else{
            median = nums3[n / 2];
        }
        
        return median;
    }
};
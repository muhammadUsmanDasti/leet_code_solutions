class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = total / 2;
        
        int l = 0;
        int r = m;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int maxLeft_nums1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int minRight_nums1 = (mid == m) ? INT_MAX : nums1[mid];

            int nums2_Left = (total + 1) / 2 - mid;
            int maxLeft_nums2 = (nums2_Left == 0) ? INT_MIN : nums2[nums2_Left - 1];
            int minRight_nums2 = (nums2_Left == n) ? INT_MAX : nums2[nums2_Left];
            if(maxLeft_nums1 <= minRight_nums2 && maxLeft_nums2 <= minRight_nums1) {
                if(total % 2 == 0){
                    return ( max(maxLeft_nums1 , maxLeft_nums2) + min(minRight_nums1 , minRight_nums2) ) / 2.0;
                }
                else {
                    return max(maxLeft_nums1, maxLeft_nums2);
                }
            }
            else if(maxLeft_nums1 > minRight_nums2) {
                 r = mid - 1; 
            }
            else {
                l = mid + 1; 
            }
        }
        return 0.0;
        
        
        
    }
};
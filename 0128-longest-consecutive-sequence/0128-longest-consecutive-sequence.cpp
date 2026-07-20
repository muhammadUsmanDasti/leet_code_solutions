class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        unordered_set<int> hashTable(nums.begin(),nums.end());
        int longest = 1;
        for(int i : hashTable) {
            int n = i;
            if(hashTable.find(n - 1) == hashTable.end()){
                int length = 1;
                while(hashTable.find(n + length) != hashTable.end()) {
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
        
    }
};
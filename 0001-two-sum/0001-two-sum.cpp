class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int MIN = INT_MIN;
        int hashSize = nums.size() * 2;
        vector<pair<int,int>> hashTable(hashSize , {MIN , -1});
        for (int i = 0; i < nums.size(); i++) {
            int index = hashFunction(nums[i] , hashSize);
            while(hashTable[index] != make_pair(MIN , -1)) {
                index = (index + 1) % hashSize;
            }
            hashTable[index] = {nums[i] , i};
        }

        for(int j = 0; j < nums.size(); j++) {
            int x = nums[j];
            int y = target - x;
            int indexY = hashFunction(y , hashSize);
            while(hashTable[indexY] != make_pair(MIN,-1)) {
                if(hashTable[indexY].first == y && hashTable[indexY].second != j) {
                    return {j , hashTable[indexY].second};
                }
                else {
                    indexY = (indexY + 1) % hashSize;
                }
            }
        }
        return {};
    }
private:
    int hashFunction(int key , int hashSize) {
        return ((key % hashSize) + hashSize) % hashSize;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> hashMap;
        for(int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin() , key.end());
            hashMap[key].push_back(strs[i]);
        }
        vector<vector<string>> groupedAnagrams;
        for(auto& pair : hashMap) {
            groupedAnagrams.push_back(pair.second);
        }
        return groupedAnagrams;
    }
};
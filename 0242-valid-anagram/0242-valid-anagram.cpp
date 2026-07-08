class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        vector<int> hashTable(26 , 0);
        for(int i=0;i<s.size();i++) {
            int index = hashFunction(s[i]);
            hashTable[index]++;
        }
        for(int j = 0; j < t.size(); j++) {
            int index = hashFunction(t[j]);
            if(hashTable[index] == 0){
                return false;
            }
            hashTable[index]--;
        }
        
        return true;
    }

private:
    int hashFunction(int key) {
        return key - 'a';
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0){
            return true;
        }
        string result = "";
        for (int k = 0; k < s.size(); k++){
            char lowerChar = tolower(s[k]);
            if((lowerChar >= 'a' && lowerChar <= 'z') || (lowerChar >= '0' && lowerChar <= '9')){
                result.push_back(lowerChar);
            }
        }
        int i = 0;
        int j = result.size() - 1;
        while(i <= j){
            if(result[i] != result[j]){
                return false;
                break;
            }
            i++;
            j--;
        }
        return true;
    }
};
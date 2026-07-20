class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string encoded = "";
        for(const string& i : strs) {
            encoded += to_string(i.size()) + "#" + i;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> output;
        int i = 0;
        while(i < s.size()) {
            string num = "";
            while(s[i] != '#'){
                num += s[i];
                i++;
            }
            int count = stoi(num);
            i++; // skip '#'
            string string1 = s.substr(i, count);
            output.push_back(string1);
            i += count;
        }
        return output;
    }
};

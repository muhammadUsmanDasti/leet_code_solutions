class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stack.push_back(tokens[i]);
            }
            else {
                int result = 0;
                int second = stoi(stack.back());
                stack.pop_back();
                int first = stoi(stack.back());
                stack.pop_back();
                if(tokens[i] == "+") {
                    result = first + second;
                }
                else if(tokens[i] == "-") {
                    result = first - second;
                }
                else if(tokens[i] == "*") {
                    result = first * second;
                }
                else if(tokens[i] == "/") {
                    result = first / second;
                }
                stack.push_back(to_string(result));
            }

           
            
        }
        return stoi(stack.back());
    }
};
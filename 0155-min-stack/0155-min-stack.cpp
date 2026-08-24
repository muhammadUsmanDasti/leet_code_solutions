class MinStack {
private:
    int minIndex = -1;
    vector<int> minStack;
    vector<int> minIndexStack;
public:
    MinStack() {

    }
    
    void push(int value) {
        minStack.push_back(value);
        if (minIndex == -1) {
            minIndex = 0;
            minIndexStack.push_back(minIndex);
        } else {
            if(value < minStack[minIndex]) {
                minIndex = minStack.size() - 1;
                minIndexStack.push_back(minIndex);
            }
        }
    }
    
    void pop() {
        if (!minStack.empty()) {
            if (minIndex != (minStack.size() - 1)) {
                minStack.pop_back();
            } else {
                minStack.pop_back();
                if (!minIndexStack.empty()) {
                    minIndexStack.pop_back();
                    if (minIndexStack.empty()){
                        minIndex = -1;
                    }
                    else {
                        minIndex = minIndexStack[minIndexStack.size() - 1];
                    }
                    
                }
                
            }
            
        }
    }
    
    int top() {
        if (!minStack.empty()){
            return minStack[minStack.size() - 1];
        } else {
            return NULL;
        }
    }
    
    int getMin() {
        if (minIndex != -1) {
            return minStack[minIndex];
        } else {
            return NULL;
        }
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
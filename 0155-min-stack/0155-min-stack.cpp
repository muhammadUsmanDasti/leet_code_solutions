class MinStack {
private:
    vector<int> minStack;
    vector<int> minValueStack;
public:
    MinStack() {

    }
    
    void push(int value) {
        minStack.push_back(value);
        if (minValueStack.empty() || value <= minValueStack[minValueStack.size() - 1]) {
            minValueStack.push_back(value);
        }
    }
    
    void pop() {
        if (!minStack.empty()) {
            if (minStack[minStack.size() - 1] == minValueStack[minValueStack.size() - 1]) {
                minValueStack.pop_back();
            } 
            minStack.pop_back();
        }
    }
    
    int top() {
        if (minStack.empty()){
            throw out_of_range("cannot call top() on an empty stack");
        } else {
            return minStack[minStack.size() - 1];
        }
    }
    
    int getMin() {
        if (minValueStack.empty()) {
            throw out_of_range("stack is empty unable to call getMin()");
        } else {
            return minValueStack[minValueStack.size() - 1];
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
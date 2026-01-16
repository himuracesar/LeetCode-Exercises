class MinStack {
private:
    vector<vector<int>> stack;
    int index = -1;

public:
    MinStack() {
        stack.clear();
    }
    
    void push(int val) {
        int minVal = (index == -1) ? INT_MAX : stack[index][1];
        minVal = min(val, minVal);

        vector<int> mv = { val, minVal };
        if(stack.size() - index == 1){
            stack.push_back(mv);
            index++;
        } else {
            index++;
            stack[index] = mv;
        }
    }
    
    void pop() {
        index--;
    }
    
    int top() {
        return stack[index][0];
    }
    
    int getMin() {
        return stack[index][1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
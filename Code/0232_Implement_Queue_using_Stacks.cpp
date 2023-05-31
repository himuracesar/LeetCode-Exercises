class MyQueue { 
private:
    stack<int> head;
    stack<int> tail;

    void migrate()
    {
        while(!tail.empty())
        {
            int val = tail.top();
            tail.pop();
            head.push(val);
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        tail.push(x);
    }
    
    int pop() {
        if(head.empty())
            migrate();

        int val = head.top();
        head.pop();

        return val;
    }
    
    int peek() {
        if(head.empty())
            migrate();

        return head.top();
    }
    
    bool empty() {
        return ((head.size() + tail.size()) == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
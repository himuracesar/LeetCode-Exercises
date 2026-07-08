class MyStack {
    private Queue<Integer> tail;
    private Queue<Integer> head;

    public MyStack() {
        tail = new LinkedList<Integer>();
        head = new LinkedList<Integer>();
    }
    
    public void push(int x) {
        if(tail.size() > 0){
            head.add(tail.poll());
        }

        tail.add(x);
    }
    
    public int pop() {
        int val = tail.poll();
        int n = head.size()-1;
        
        for(var i = 0; i < n; i++){
            head.add(head.poll());
        }

        if(!head.isEmpty())
            tail.add(head.poll());

        return val;
    }
    
    public int top() {
        return tail.peek();
    }
    
    public boolean empty() {
        return head.isEmpty() && tail.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */
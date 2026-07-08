class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        priority_queue<int, vector<int>, greater<int>> st = starts;
        priority_queue<int, vector<int>, greater<int>> ed = ends;

        st.push(startTime);
        ed.push(endTime);

        int overlaps = 0;
        while(!st.empty() || !ed.empty()){
            if(!st.empty() && ed.empty()){
                overlaps++;
                st.pop();
            } else if(st.empty() && !ed.empty()){
                overlaps--;
                ed.pop();
            } else if(st.top() < ed.top()){
                overlaps++;
                st.pop();
            } else {
                overlaps--;
                ed.pop();
            }

            if(overlaps == 3)
                return false;
        }

        starts.push(startTime);
        ends.push(endTime);

        return true;
   }

private:
    priority_queue<int, vector<int>, greater<int>> starts;
    priority_queue<int, vector<int>, greater<int>> ends;

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
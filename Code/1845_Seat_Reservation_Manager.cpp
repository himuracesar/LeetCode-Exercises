class SeatManager {
public:
    SeatManager(int n) {
        for(auto i = 1; i <= n; i++)
            seats.push(i);
    }
    
    int reserve() {
        int seat = seats.top();
        seats.pop();

        return seat;
    }
    
    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }


private:
    priority_queue<int, vector<int>, greater<int>> seats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
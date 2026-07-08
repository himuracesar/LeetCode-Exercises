class LRUCache {
private:
    vector<vector<long>> table;
    unordered_map<int, int> keys;
    int capacity = 0;

    long lastAccess = 0L;

    long getTimeInMilliseconds(){
        auto now = chrono::system_clock::now();
        auto duration = now.time_since_epoch();

        //long milliseconds = chrono::duration_cast<chrono::milliseconds>(duration).count();
        long milliseconds = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();

        return milliseconds;
    }

    void heapifyDown(int index){
        int child1 = 2 * index + 1;
        int child2 = 2 * index + 2;

        if(child1 >= table.size() && child2 >= table.size())
            return;
        
        if(child1 < table.size() && child2 >= table.size()){
            swap(index, child1);
            heapifyDown(child1);

            return;
        }

        int val1 = (int)table[child1][2];
        int val2 = (int)table[child2][2];

        //cout << "index:: " << index << " ch1:: " << child1 << " = " << val1 << " ch2:: " << child2 << " = " << val2  << endl;

        if(val1 < val2){
            swap(index, child1);
            heapifyDown(child1);
        } else {
            swap(index, child2);
            heapifyDown(child2);
        }
    }

    void swap(int orig, int dest){
        keys[(int)table[orig][0]] = dest;
        keys[(int)table[dest][0]] = orig;

        auto v = table[orig];
        table[orig] = table[dest];
        table[dest] = v;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        lastAccess = getTimeInMilliseconds();
    }
    
    int get(int key) {
        if(keys.find(key) == keys.end())
            return -1;

        table[keys[key]][2] = lastAccess++;
        heapifyDown(keys[key]);

        return (int)table[keys[key]][1];
    }
    
    void put(int key, int value) {
        if(keys.find(key) != keys.end()){
            table[keys[key]][1] = value;
            table[keys[key]][2] = lastAccess++;

            heapifyDown(keys[key]);
        } else if(table.size() < capacity){
            table.push_back({ (long)key, (long)value, lastAccess++ });
            keys[key] = table.size()-1;
        } else {
            keys.erase(table[0][0]);
            keys[key] = 0;

            table[0][0] = key;
            table[0][1] = value;
            table[0][2] = lastAccess++;

            heapifyDown(0);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
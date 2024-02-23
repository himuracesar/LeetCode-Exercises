class FrequencyTracker {
private:
    map<int,int> nums;
    map<int,int> freqs;

public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        freqs[nums[number]]--;
        nums[number]++;
        freqs[nums[number]]++;
    }
    
    void deleteOne(int number) {
        if(nums[number] > 0){
            freqs[nums[number]]--;
            nums[number]--;
            freqs[nums[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return freqs[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
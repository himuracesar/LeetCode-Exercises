class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        queue<int> q;

        if(nums.size() < 3)
            return 0;

        int last_diff = nums[0] - nums[1];
        int size = 2;
        for(auto i = 2; i < nums.size(); i++){
            int diff = nums[i - 1] - nums[i];
            if(last_diff == diff)
                size++;
            else {
                last_diff = diff;

                if(size >= 3)
                    q.push(size);

                size = 2;
            }
        }

        if(size >= 3)
            q.push(size);

        int total = 0;
        while(!q.empty()){
            //cout << q.front() << endl;
            if(q.front() == 3){
                total++;
            } else {
                int np = q.front() - 3 + 2;
                int nr = (q.front() - 2) / 2;

                total += nr * np;

                if((q.front() - 2) % 2 != 0)
                    total += nr + 1;
            }
            q.pop();
        }

        //1,2,3,4,5,6,7
        //    5,4,3,2,1 ==> 6 
        // 2 * 6 + 3
        //1,2,3,4,5
        //    3,2,1 ==> 4
        //1,2,3,4,5,6
        //    4,3,2,1

        return total;
    }
};
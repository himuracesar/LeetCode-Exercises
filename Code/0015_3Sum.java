class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashMap<Integer, Integer> hmNums = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> tuplas =  new HashMap<Integer, Integer>();
        HashMap<String, Integer> hmTriplets = new HashMap<String, Integer>();
        
        List<List<Integer>> triplets = new ArrayList();
        
        if(nums.length < 3)
            return null;
        
        for(int pivot = 0; pivot < nums.length; pivot++)
        {
            if(hmNums.get(nums[pivot]) != null)
                continue;
            else
            {
                hmNums.put(nums[pivot], nums[pivot]);
                tuplas.clear();
                
                for(int i = pivot + 1; i < nums.length; i++)
                {
                    if(tuplas.get(nums[i]) != null)
                    {
                        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
                        pq.add(nums[pivot]);
                        pq.add(tuplas.get(nums[i]));
                        pq.add(nums[i]);
                        
                        String key = "";
                        while(pq.size() > 0)
                        {
                            key += Integer.toString(pq.poll());
                        }
                        
                        if(hmTriplets.get(key) == null)
                        {
                            hmTriplets.put(key, 0);   
                            
                            //System.out.println("Find:: " + nums[i]);
                            List<Integer> list = new ArrayList();
                            list.add(nums[pivot]);
                            list.add(tuplas.get(nums[i]));
                            list.add(nums[i]);

                            triplets.add(list);
                        }
                    }
                    else
                    {
                        int k = 0 - nums[pivot] - nums[i];
                        //System.out.println("Add:: " + nums[pivot] + " --- " + k + " -- " + nums[i]);
                        tuplas.put(k, nums[i]);
                    }
                }
            }
        }
        
        return triplets;
    }
}
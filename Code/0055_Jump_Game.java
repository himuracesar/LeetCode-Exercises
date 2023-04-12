class Solution {
    public boolean canJump(int[] nums) {
        HashMap<Integer, Integer> posVisited = new HashMap<Integer, Integer>();
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(0);

        while(!q.isEmpty())
        {
            int index = q.poll();
            if(index + nums[index] >= nums.length - 1)
                return true;

            for(int i = 0; i <= nums[index]; i++)
            {
                int pos = index + i;
                if(posVisited.get(pos) == null)
                {
                    posVisited.put(pos, pos);
                    if(nums[pos] > 0)
                        q.add(pos);
                }
            }
        }

        return false;
    }
}
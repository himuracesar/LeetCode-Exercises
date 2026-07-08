class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<Integer>();

        for(var i = 0; i < nums1.length; i++){
            if(map.get(nums1[i]) == null)
                map.put(nums1[i], 1);
            
            map.put(nums1[i], map.get(nums1[i]) + 1);
        }

        Set<Integer> cache = new HashSet<Integer>();
        for(var i = 0; i < nums2.length; i++){
            if(map.get(nums2[i]) != null && !cache.contains(nums2[i])){
                list.add(nums2[i]);
                cache.add(nums2[i]);
            }
        }

        return list.stream().mapToInt(i->i).toArray();
    }
}
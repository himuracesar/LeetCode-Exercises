class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        LinkedList<Integer> list = new LinkedList<Integer>();
        
        int im = 0;
        int in = 0;
        while(im < m || in < n){
            if(im == m)
                list.add(nums2[in++]);
            else if(in == n)
                list.add(nums1[im++]);
            else{
                if(nums1[im] < nums2[in])
                    list.add(nums1[im++]);
                else
                    list.add(nums2[in++]);
            }
        }

        im = 0;
        while(list.peek() != null){
            nums1[im++] = list.remove();
        }
    }
}
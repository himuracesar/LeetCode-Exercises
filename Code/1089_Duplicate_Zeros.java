class Solution {
    public void duplicateZeros(int[] arr) {
        Queue<Integer> q = new LinkedList<>();

        for(var i = 0; i < arr.length; i++){
            if(!q.isEmpty()){
                q.add(arr[i]);
                arr[i] = q.peek();
                q.remove();
            } 

            if(i < arr.length-1 && arr[i] == 0){
                q.add(arr[i+1]);
                arr[i+1] = 0;
                i++;
            }
        }
    }
}
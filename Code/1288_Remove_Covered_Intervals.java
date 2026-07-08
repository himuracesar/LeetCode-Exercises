class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        int drops = 0;

        for(var i = 0; i < intervals.length; i++){
            int start1 = intervals[i][0];
            int end1 = intervals[i][1];
            for(var j = 0; j < intervals.length; j++){
                if(i == j)
                    continue;
                
                int start2 = intervals[j][0];
                int end2 = intervals[j][1];
                if(start2 <= start1 && end1 <= end2){
                    drops++;
                    break;
                }
            }
        }

        return intervals.length - drops;
    }
}
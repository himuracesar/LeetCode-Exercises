class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;

        int start = 0;
        int end = n * m;
        int mid = 0;

        int row = 0;
        int col = 0;

        while(start <= end)
        {
            mid = (start + end) / 2;

            row = mid / m;
            col = mid - m * row;

            if(row >= n || col >= m)
                return false;

            if(target < matrix[row][col])
                end = mid - 1;
            else if(target > matrix[row][col])
                start = mid + 1;
            else
                return true;
        }

        return false;
    }
}
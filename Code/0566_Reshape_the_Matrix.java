class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int n = mat.length;
        int m = mat[0].length;

        if(n * m != r * c)
            return mat;

        int[][] matres = new int[r][c];

        int col = 0;
        int row = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matres[row][col] = mat[i][j];
                if(col + 1 == c){
                    col = 0;
                    row++;
                }
                else
                    col++;
            }
        }

        return matres;
    }
}
class Solution {
    public int numEnclaves(int[][] grid) {
        int landsNoWalk = 0;

        int visited[][] = new int[grid.length][grid[0].length];

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0].length; j++)
                visited[i][j] = -1;
        }

        Queue<int[]> q = new LinkedList<>();

        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[0]. length; j++){
                if(visited[i][j] > -1)
                    continue;

                if(grid[i][j] == 1)
                    q.offer(new int[]{ i, j });
                else {
                    visited[i][j] = grid[i][j];
                    continue;
                }

                int lands = 0;
                boolean isWalk = false;
                
                while(!q.isEmpty()){
                    int coord[] = q.poll();

                    int x = coord[0];
                    int y = coord[1];

                    if(visited[x][y] > -1)
                        continue;

                    visited[x][y] = grid[x][y];
                    lands++;

                    if(x-1 < 0 || x+1 == grid.length || y-1 < 0 || y+1 == grid[0].length)
                        isWalk = true;
                    
                    if(x-1 >= 0 && visited[x-1][y] == -1 && grid[x-1][y] == 1)
                        q.offer(new int[]{ x-1, y });
                    if(x+1 < grid.length && visited[x+1][y] == -1 && grid[x+1][y] == 1)
                        q.offer(new int[]{ x+1, y });
                    if(y-1 >= 0 && visited[x][y-1] == -1 && grid[x][y-1] == 1)
                        q.offer(new int[]{ x, y-1 });
                    if(y+1 < grid[0].length && visited[x][y+1] == -1 && grid[x][y+1] == 1)
                        q.offer(new int[]{ x, y+1 });
                }

                if(!isWalk)
                    landsNoWalk += lands;
            }
        }

        return landsNoWalk;
    }
}
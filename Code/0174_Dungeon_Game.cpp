class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> damages(dungeon.size(), vector<int>(dungeon[0].size(), -1));

        return calculateMinimumHP(dungeon, 0, 0, damages) + 1;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon, int row, int col, vector<vector<int>>& damages){
        if(row == dungeon.size() || col == dungeon[0].size()){
            return INT_MAX;
        }

        if(damages[row][col] > -1){
            return damages[row][col];
        }

        int damage = 0;
        int life = 0;

        if(dungeon[row][col] <= 0){
            damage = abs(dungeon[row][col]);
        } else {
            life = dungeon[row][col];
        }
        
        int right = calculateMinimumHP(dungeon, row, col + 1, damages);
        int down = calculateMinimumHP(dungeon, row + 1, col, damages);
 
        damage += (right == INT_MAX && down == INT_MAX) ? 0 : min(right, down);

        int currentDamage = life - damage;

        damages[row][col] = (currentDamage <= 0) ? abs(currentDamage) : 0;

        return damages[row][col];
    }
};
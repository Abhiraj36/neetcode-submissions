class Solution {
public:

int count_island(vector<vector<int>>& grid, int i , int j, int& count){
   //check if its with bounds
   if(i < 0 || j <0 || i >= grid.size() || j>=grid[0].size()) return 0;
   if(grid[i][j] == 0) return 0; //useless neighbour

   grid[i][j] = 0;

   //call th neighbours and see if they are helpful

   if(count_island(grid, i-1, j, count) == 1) count++; //up
   if(count_island(grid, i+1, j, count) == 1) count++; //below
   if(count_island(grid, i, j-1, count) == 1) count++; //left
   if(count_island(grid, i, j+1, count) == 1) count++; //right

    return 1;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        int Max =0;
        for(int i =0; i < m ; i++) {
            for (int j =0; j <n; j++) {
                int count  = 1;
                //check if value is 1
                if(grid[i][j] == 1){
                    count_island(grid, i, j, count);
                    Max = max(Max, count);
                }
            }
        }
return Max;

    }
};
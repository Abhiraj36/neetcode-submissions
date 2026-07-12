class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void DFS(vector<vector<int>>& heights, int i, int j, int prevHeight, vector<vector<bool>>& visited) {
        int m = heights.size(), n = heights[0].size();
        
        // Base conditions
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (heights[i][j] < prevHeight || visited[i][j]) return;
        
        visited[i][j] = true;
        
        // Explore all 4 directions
        for (auto &dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            DFS(heights, newI, newJ, heights[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // DFS from Pacific (top row, left column)
        for (int i = 0; i < m; i++)
            DFS(heights, i, 0, INT_MIN, pacific);
        for (int j = 0; j < n; j++)
            DFS(heights, 0, j, INT_MIN, pacific);
        
        // DFS from Atlantic (bottom row, right column)
        for (int i = 0; i < m; i++)
            DFS(heights, i, n - 1, INT_MIN, atlantic);
        for (int j = 0; j < n; j++)
            DFS(heights, m - 1, j, INT_MIN, atlantic);
        
        // Collect cells reachable by both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        
        return result;
    }
};

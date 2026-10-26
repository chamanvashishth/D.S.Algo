class Solution {
private:
    int rows, cols;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        // Stop if we're outside the grid or on water/already visited.
        if (r < 0 || c < 0 || r >= rows || c >= cols ||
            grid[r][c] == 1) {
            return;
        }

        // Mark this land cell as visited.
        grid[r][c] = 1;

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        // Remove all land connected to the boundary.
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] == 0) dfs(grid, r, 0);
            if (grid[r][cols - 1] == 0) dfs(grid, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0) dfs(grid, 0, c);
            if (grid[rows - 1][c] == 0) dfs(grid, rows - 1, c);
        }

        int closedIslands = 0;

        // Any remaining unvisited land belongs to a closed island.
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    closedIslands++;
                    dfs(grid, r, c);
                }
            }
        }

        return closedIslands;
    }
};
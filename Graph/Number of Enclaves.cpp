class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                q.push({i, 0});
                vis[i][0] = true;
            }
            if (grid[i][c - 1] == 1 && !vis[i][c - 1]) {
                q.push({i, c - 1});
                vis[i][c - 1] = true;
            }
        }

        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                q.push({0, j});
                vis[0][j] = true;
            }
            if (grid[r - 1][j] == 1 && !vis[r - 1][j]) {
                q.push({r - 1, j});
                vis[r - 1][j] = true;
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i - 1 >= 0 && !vis[i - 1][j] && grid[i - 1][j] == 1) {
                vis[i - 1][j] = true;
                q.push({i - 1, j});
            }

            if (j + 1 < c && !vis[i][j + 1] && grid[i][j + 1] == 1) {
                vis[i][j + 1] = true;
                q.push({i, j + 1});
            }

            if (i + 1 < r && !vis[i + 1][j] && grid[i + 1][j] == 1) {
                vis[i + 1][j] = true;
                q.push({i + 1, j});
            }

            if (j - 1 >= 0 && !vis[i][j - 1] && grid[i][j - 1] == 1) {
                vis[i][j - 1] = true;
                q.push({i, j - 1});
            }
        }

        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};

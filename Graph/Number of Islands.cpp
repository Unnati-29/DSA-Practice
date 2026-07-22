class Solution {
public:
    void dfs(int r,vector<vector<bool>>& visited,vector<vector<char>>& grid,int c){
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n){
            return;
        }

        if (grid[r][c] == '0' || visited[r][c]){
            return;
        }

        visited[r][c] = true;

        dfs(r - 1, visited, grid, c);
        dfs(r + 1, visited, grid, c);
        dfs(r , visited, grid, c - 1);
        dfs(r , visited, grid, c + 1); 
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int count =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(i,visited,grid,j);
                }
            }
        }
        return count;
    }
};

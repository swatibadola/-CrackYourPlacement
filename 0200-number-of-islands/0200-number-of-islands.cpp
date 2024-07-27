class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //traverse all neighbours and mark them if not visited
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    if((delrow == -1 && delcol == -1) || (delrow == -1 && delcol == 1) || (delrow == 1 && delcol == -1) || (delrow == 1 && delcol == 1)) continue;
                    int neighrow = row+delrow;
                    int neighcol = col+delcol;
                    if(neighrow >= 0 && neighrow < n && neighcol >=0 && neighcol < m && grid[neighrow][neighcol]=='1' && !vis[neighrow][neighcol]){
                        vis[neighrow][neighcol] = 1;
                        q.push({neighrow, neighcol});
                    }
                }
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
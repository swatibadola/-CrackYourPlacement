class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col, int delrow[], int delcol[], vector<vector<int>>& vis){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(board, nrow, ncol, delrow, delcol, vis);
            }
        }
        
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(board, 0, j, delrow, delcol, vis);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(board, n-1, j, delrow, delcol, vis);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(board, i, 0, delrow, delcol, vis);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(board, i, m-1, delrow, delcol, vis);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
class Solution {
    void dfs(int row,int col,int del[],vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=board.size();
        int m = board[0].size();
        for(int i=0;i<4;i++){
            int nrow = row+del[i];
            int ncol = col+del[i+1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,del,board,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m = board[0].size();
        int del[]={-1,0,+1,0,-1};
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && ((i==0 && board[0][j] == 'O') || (j==0 && board[i][0] == 'O') || (i==n-1 && board[n-1][j] == 'O') || (j==m-1 && board[i][m-1] == 'O'))){
                    dfs(i,j,del,board,vis);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    
    }
};
class Solution {
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis,int del[],int n, int m){
        vis[row][col]=1;
       
        for(int i=0;i<4;i++){
            int nrow = row+del[i];
            int ncol = col+del[i+1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid,vis,del,n,m);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
         
        int del[] = {-1,0,+1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                     count++;
                    dfs(i,j,grid,vis,del,n,m);
                }
            }
            
        }
        return count;
    }
};
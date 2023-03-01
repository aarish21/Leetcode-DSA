class Solution {
public:
    int minPathSum(int i,int j,vector<vector < int>> &dp,vector<vector < int>> &grid){
        if(i==0 && j==0)  {
            return grid[i][j];
        }
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
       
        int up = grid[i][j]+ minPathSum(i-1,j,dp,grid);
       
        int left = grid[i][j]+ minPathSum(i,j-1,dp,grid);
      
        return dp[i][j] = min(up,left);
            
    
    }
     int minPathSum(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return minPathSum(n-1, m-1, dp,grid);
    }
};
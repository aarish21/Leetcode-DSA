class Solution {
public:
    int uniquePaths(int m, int n,vector<int> &dp,vector<vector<int>> &grid) {
        
    for(int i=0;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j == 0) temp[j]=grid[i][j];
            else{
                int up=grid[i][j];
                int left = grid[i][j];
                if(i>0) up += dp[j];
                else up+= 1e9;
                if(j>0) left += temp[j-1];
                else left+= 1e9;

                temp[j] = min(up,left);
            }
        }
        dp = temp;
        
    }

        return dp[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);
        return uniquePaths(m,n,dp,grid);
    }
};
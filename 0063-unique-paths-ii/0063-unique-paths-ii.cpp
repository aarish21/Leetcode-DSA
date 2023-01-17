class Solution {
public:
    int uniquePaths(int m, int n,vector<vector<int>> &dp,vector<vector<int>> &obstacleGrid) {
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j] == 1) {
                dp[i][j]=0;continue;
            }
            if(i==0 && j==0) {
                dp[i][j]=1;
                continue;
            }
            int up=0;
            int left = 0;
            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            dp[i][j] = up+left;
        }
        
    }

        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
         vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquePaths(m,n,dp,obstacleGrid);
    }
};
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j]; 
        int down=0,right=0;
        if(i>0 && arr[i][j]!=1)
            down = f(i-1,j,arr,dp);
        if(j>0 && arr[i][j]!=1)
            right = f(i,j-1,arr,dp);
        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
};
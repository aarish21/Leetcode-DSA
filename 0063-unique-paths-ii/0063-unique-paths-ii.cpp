class Solution {
public:
    int uniquePathsWithObstacles(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0; 
        if(i==0 && j == 0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = uniquePathsWithObstacles(i-1,j,obstacleGrid,dp);
        int left = uniquePathsWithObstacles(i,j-1,obstacleGrid,dp);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> prev(m,0);
    
        for(int i=0;i<n;i++){
             vector<int> cur(m,0);
            for(int j=0;j<m;j++){
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
                    cur[j]=0; continue;
                }
                if(i==0 && j==0){
                    cur[j]=1;  continue;
                }
                
                 
                int up = 0, left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = cur[j-1];
                    
                cur[j] = up+left;
            
            }
            prev = cur;
        }
        
        
    return prev[m-1];
     
    }
};
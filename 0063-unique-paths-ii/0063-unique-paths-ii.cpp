class Solution {
public:
    int uniquePaths(int m, int n,vector<int> &dp,vector<vector<int>> &obstacleGrid) {
        
    for(int i=0;i<m;i++){
         vector<int> cur(n,0);
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j] == 1) {
                cur[j]=0;continue;
            }
            if(i==0 && j==0) {
                cur[j]=1;
                continue;
            }
            int up=0;
            int left = 0;
            if(i>0) up = dp[j];
            if(j>0) left = cur[j-1];
            cur[j] = up+left;
        }
        dp = cur;
        
    }

        return dp[n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<int> prev(m,0);
//     for(int i=0; i<n; i++){
//         vector<int> temp(m,0);
//         for(int j=0; j<m; j++){
//             if(maze[i][j]==1){
//                 temp[j]=0;
//                 continue;
//             }
//             if(i==0 && j==0){
//                 temp[j]=1;
//                 continue;
//             }
            
//             int up=0;
//             int left =0;
            
//             if(i>0)
//                 up = prev[j];
//             if(j>0)
//                 left = temp[j-1];
                
//             temp[j] = up + left;
//         }
//         prev = temp;
//     }
    
    // return prev[n-1];
         vector<int> dp(n,0);
        
        return uniquePaths(m,n,dp,obstacleGrid);
    }
};
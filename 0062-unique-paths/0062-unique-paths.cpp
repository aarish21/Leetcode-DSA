class Solution {
public:
    
      // if(dp[i][j] !=-1) return dp[i][j];
    
//     int up = uniquePaths(i-1,j,dp);
//     int left = uniquePaths(i,j-1,dp);
    
//     return dp[i][j] = up+left;
    
    int uniquePaths(int m, int n,vector<vector<int>> &dp) {
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
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
    int uniquePaths(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquePaths(m,n,dp);
    }
};
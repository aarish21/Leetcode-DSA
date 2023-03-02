class Solution {
public:
//     int minFallingPathSum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp) {
//         if(j<0 || j>=matrix[0].size()) return 1e9;
//         if(i==0) return matrix[0][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up  = matrix[i][j] + minFallingPathSum(i-1,j,matrix,dp);
//         int l =  matrix[i][j] + minFallingPathSum(i-1,j-1,matrix,dp);
//         int r =  matrix[i][j] + minFallingPathSum(i-1,j+1,matrix,dp);
        
//         return dp[i][j]=min(up,min(l,r));
        
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1;i<n;i++){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+dp[i-1][j],l=matrix[i][j],r=matrix[i][j];
                
                int leftDiagonal= matrix[i][j];
            if(j>0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += 1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j<m-1) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += 1e9;
            
            dp[i][j] = min(up, min(leftDiagonal,rightDiagonal));
            }
        }
        
        int mini = INT_MAX;
        for(int j=0; j<m;j++){
            int ans = dp[n-1][j];
            mini = min(mini,ans);
        }
    
        return mini;
    }
};
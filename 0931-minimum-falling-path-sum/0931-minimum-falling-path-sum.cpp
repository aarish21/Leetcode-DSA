class Solution {
public:
    int minFallingPathSum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp) {
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up  = matrix[i][j] + minFallingPathSum(i-1,j,matrix,dp);
        int l =  matrix[i][j] + minFallingPathSum(i-1,j-1,matrix,dp);
        int r =  matrix[i][j] + minFallingPathSum(i-1,j+1,matrix,dp);
        
        return dp[i][j]=min(up,min(l,r));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0; j<m;j++){
            int ans = minFallingPathSum(n-1,j,matrix,dp);
            mini = min(mini,ans);
        }
    
        return mini;
    }
};
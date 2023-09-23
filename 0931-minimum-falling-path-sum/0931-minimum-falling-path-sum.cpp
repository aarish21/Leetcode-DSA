class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans = INT_MAX;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int j=0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int down2 = 1e9,down3 = 1e9;
                int down1 = matrix[i][j]+dp[i+1][j];
                if(j<n-1)
                    down2 = matrix[i][j]+dp[i+1][j+1];
                 if(j>0)
                    down3 = matrix[i][j]+dp[i+1][j-1];
                dp[i][j] = min(down1,min(down2,down3));
            }
        }
        for(int j=0;j<n;j++){
            ans = min(ans,dp[0][j]);
        }
        
        return ans;
        
    }
};
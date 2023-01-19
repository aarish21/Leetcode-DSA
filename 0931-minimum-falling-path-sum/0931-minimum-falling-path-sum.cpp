class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j] = matrix[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int d = matrix[i][j]+dp[i+1][j];
                int diaR = INT_MAX;
                if(j<n-1)
                diaR = matrix[i][j]+dp[i+1][j+1];
                int diaL = INT_MAX;
                if(j>0)
                diaL = matrix[i][j]+dp[i+1][j-1];
                dp[i][j] = min(d,min(diaL,diaR));
            }
        }
        int mini = INT_MAX;
    
        for(int j=0; j<n;j++){
            mini = min(mini,dp[0][j]);
        }
        return mini;
    }
};
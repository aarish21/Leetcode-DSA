class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(i==n-1){
            return arr[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down1 = arr[i][j]+f(i+1,j,n,arr,dp);
        int down2 = arr[i][j]+f(i+1,j+1,n,arr,dp);
        
        return dp[i][j] = min(down1,down2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,0,triangle.size(),triangle,dp);
    }
};
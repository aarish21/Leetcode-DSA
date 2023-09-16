class Solution {
public:
    bool f(string s,string t, int n,int m, vector<vector<int>> &dp){
        if(n==0) return true;
        if(m==0) return false;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n-1]==t[m-1])
           return dp[n][m] = f(s,t,n-1,m-1,dp);
        return dp[n][m] = f(s,t,n,m-1,dp);
    }
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // for(int i=0;i<=m;i++) dp[0][i] = true;
        // for(int i=0;i<n;i++) dp[i][0] = false;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0) dp[i][j] = true;
                else if(j==0) dp[i][j] = false;
                else if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];
     
    }
};
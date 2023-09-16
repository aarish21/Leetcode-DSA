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
        return f(s,t,s.size(),t.size(),dp);
    }
};
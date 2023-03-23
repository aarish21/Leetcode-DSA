class Solution {
public:
    int helper(string s1, string s2,int i, int j,vector<vector<int>> &dp){
        
        if(i==0) return j+1;
        if(j==0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]) return dp[i][j] = 0 + helper(s1,s2,i-1,j-1,dp);
        
        int insert = 1+helper(s1,s2,i,j-1,dp);
        int deletion = 1+helper(s1,s2,i-1,j,dp);
        int replace = 1+helper(s1,s2,i-1,j-1,dp);
        return dp[i][j] = min(insert,min(deletion,replace));
        
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                if(s1[i-1]==s2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else{
                    int insert = 1+dp[i][j-1];
                    int deletion = 1+dp[i-1][j];
                    int replace = 1+dp[i-1][j-1];
                    dp[i][j] = min(insert,min(deletion,replace));
                }
                
            }
        }
        for(int i =0;i<=n;i++){
            for(int j =0;j<=m;j++){
                 cout<<dp[i][j];
            }
           cout<<endl;
        }
        
        return dp[n][m];
    }
};
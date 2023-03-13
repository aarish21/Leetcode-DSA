class Solution {
public:
    int helper(int i,int j,string s1, string s2, vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) return dp[i][j] = 1+helper(i-1,j-1,s1,s2,dp);
            
        return dp[i][j] = max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
    }
     int longestCommonSubsequence(string s1, string s2) 
    {
//         int n = s1.length();
//         int m = s2.length();
//         vector<int> curr(m+1,0), prev(m+1,0);

//         // no need to write base case as we already declare our dp as 0

        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=1;j<=m;j++)
        //     {
        //         if(s1[i-1]==s2[j-1])
        //         {
        //             curr[j] = 1 + prev[j-1];
        //         }
        //         else
        //         {
        //             curr[j] = max(curr[j-1],prev[j]);
        //         }
        //     }
        //     prev = curr;
        // }

//         return curr[m];
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
           
        }


        return dp[n][m];
    }

};
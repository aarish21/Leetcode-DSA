class Solution {
public:
    int helper(int i,int j, vector<int>& num1, vector<int>& num2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0,notTake=0;
        if(num1[i]==num2[j])
            take = 1+helper(i-1,j-1,num1,num2,dp);
        
        else
            notTake = max(helper(i-1,j,num1,num2,dp),helper(i,j-1,num1,num2,dp));
        
        return dp[i][j] = max(take,notTake);
    }
    int maxUncrossedLines(vector<int>& num1, vector<int>& num2) {
    vector<vector<int>> dp(num1.size(),vector<int>(num2.size(),-1));
       return helper(num1.size()-1,num2.size()-1,num1,num2,dp);
    }
};
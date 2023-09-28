class Solution {
public:
    int f(int i, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(i==0){
            return 1e9;
        }
        if(dp[i-1][amount] != -1) dp[i][amount];
        int take = 1e9;
        if(coins[i-1]<=amount)
            take = 1+f(i,coins,amount-coins[i-1],dp);
        int notTake = f(i-1,coins,amount,dp);
        return dp[i-1][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int j=1;j<=amount;j++) dp[0][j] = 1e9;
        
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                int take = 1e9;
                if(coins[i-1]<=j)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int ans = dp[coins.size()][amount];
        return ans==1e9 ? -1 : ans;
    }
};
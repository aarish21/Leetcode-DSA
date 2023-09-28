class Solution {
public:
     int f(int i, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount==0) return 1;
        if(i==0){
            return 0;
        }
        if(dp[i][amount] != -1) dp[i][amount];
        int take = 1e9;
        if(coins[i]<=amount)
            take = 1+f(i,coins,amount-coins[i],dp);
        int notTake = f(i-1,coins,amount,dp);
        return dp[i][amount] = min(take,notTake);
    }
    int change(int amount, vector<int>& coins) {
       
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=0;i<=coins.size();i++) dp[i][0] = 1;
        
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                dp[i][j] = dp[i-1][j];
                if(coins[i-1]<=j)
                    dp[i][j] += dp[i][j - coins[i - 1]] ;
            }
        }
        return dp[coins.size()][amount];
    }
};
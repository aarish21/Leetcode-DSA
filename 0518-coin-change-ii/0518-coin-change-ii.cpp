class Solution {
public:
    int helper(int ind,int amount, vector<int> &coin,vector<vector<int>> &dp){
    
        if(ind == 0){
            return (amount%coin[0]==0);
            
            
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = helper(ind-1,amount,coin,dp);
        int take = 0;
        if(coin[ind]<=amount) 
            take = helper(ind,amount-coin[ind],coin,dp);
        return dp[ind][amount] = take+notTake;
        
        
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return helper(coins.size()-1, amount, coins, dp);
    }
};
class Solution {
public:
    int helper(int ind,int amount, vector<int> &coin,vector<vector<int>> &dp){
    
        if(ind == 0){
            if(amount%coin[0]==0) return amount/coin[0];
            
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = helper(ind-1,amount,coin,dp);
        int take = 1e9;
        if(coin[ind]<=amount) 
            take = 1 + helper(ind,amount-coin[ind],coin,dp);
        return dp[ind][amount] = min(take,notTake);
        
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(coins.size()-1,amount,coins,dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};
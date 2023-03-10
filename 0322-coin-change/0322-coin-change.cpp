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
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
       for(int i=0; i<=amount; i++){
        if(i%coins[0] == 0)  
            dp[0][i] = i/coins[0];
        else dp[0][i] = 1e9;
    }
       
       for(int ind = 1; ind<coins.size(); ind++){
        for(int target = 0; target<=amount; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(coins[ind]<=target)
                take = 1 + dp[ind][target - coins[ind]];
                
             dp[ind][target] = min(notTake, take); 
            }
         }
    
        int ans = dp[coins.size()-1][amount];
        if(ans >=1e9) return -1;
        return ans;
    }
};
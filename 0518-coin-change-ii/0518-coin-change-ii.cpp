class Solution {
public:
    int change(int amount, vector<int>& coins) {
       
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=0;i<=coins.size();i++) dp[i][0] = 1;
        
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                int notTaken = dp[i-1][j];
                int taken = 0;
                if(coins[i-1]<=j)
                    taken = dp[i][j-coins[i-1]];
                dp[i][j] = notTaken + taken;
            }
        }
        return dp[coins.size()][amount];
    }
};
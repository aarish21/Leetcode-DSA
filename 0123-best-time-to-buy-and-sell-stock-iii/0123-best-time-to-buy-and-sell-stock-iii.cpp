class Solution {
public:
    int helper(int ind,int buy,int count,vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || count == 2) return 0;
        int profit;
        if(dp[ind][buy][count]!=-1) return dp[ind][buy][count];
        if(buy==0){
            profit = max(0+helper(ind+1,0,count,prices,dp),-prices[ind]+helper(ind+1,1,count,prices,dp));
        } 
        if(buy == 1) {
            profit = max(0+helper(ind+1,1,count,prices,dp),prices[ind]+helper(ind+1,0,count+1,prices,dp));
        }
        
       return dp[ind][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,0,0,prices,dp);
    }
};
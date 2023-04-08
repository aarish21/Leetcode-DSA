class Solution {
public:
    int helper(int i,int buy,int count,vector<int>& prices, int n,vector<vector<vector<int>>> &dp) {
        if(i == n || count==2) return 0;
        int profit;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(buy==0){
            profit = max(helper(i+1,0,count,prices,n,dp),-prices[i]+helper(i+1,1,count,prices,n,dp));
        }
        if(buy == 1){
            profit = max(helper(i+1,1,count,prices,n,dp),prices[i]+helper(i+1,0,count+1,prices,n,dp));
        }
        return dp[i][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return helper(0,0,0,prices,prices.size(),dp);
    }
};
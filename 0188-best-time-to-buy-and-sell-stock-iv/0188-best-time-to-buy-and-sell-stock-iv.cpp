class Solution {
public:
    int helper(int i,int buy,int count,vector<int>& prices, int n,vector<vector<vector<int>>> &dp,int k) {
        if(i == n || count==k) return 0;
        int profit;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(buy==0){
            profit = max(helper(i+1,0,count,prices,n,dp,k),-prices[i]+helper(i+1,1,count,prices,n,dp,k));
        }
        if(buy == 1){
            profit = max(helper(i+1,1,count,prices,n,dp,k),prices[i]+helper(i+1,0,count+1,prices,n,dp,k));
        }
        return dp[i][buy][count] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k,-1)));
        return helper(0,0,0,prices,prices.size(),dp,k);
    }
};
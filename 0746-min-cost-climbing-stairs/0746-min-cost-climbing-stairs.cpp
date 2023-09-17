class Solution {
public:
   
    int f(int ind,int n, vector<int>& cost,vector<int>& dp){
        if(ind>n) return 0; 
        if(dp[ind]!=-1) return dp[ind];
        int left = cost[ind]+f(ind+1,n,cost,dp);
        int right = cost[ind]+f(ind+2,n,cost,dp);
        return dp[ind] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2,0);
        int n = cost.size()-1;
        for(int ind=n;ind>=0;ind--){
            dp[ind] = cost[ind]+ min(dp[ind+1],dp[ind+2]);
        }
        return min(dp[0],dp[1]);
    }
};
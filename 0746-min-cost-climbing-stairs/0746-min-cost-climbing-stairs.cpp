class Solution {
public:
    // int f(int ind, vector<int>& cost,vector<int>& dp){
    //     if(ind==0 || ind == 1) return min(cost[0],cost[1]);
    //     if(dp[ind]!=-1) return dp[ind];
    //     int left = cost[ind]+f(ind-1,cost,dp);
    //     int right = INT_MAX;
    //     if(ind>1)
    //     right = cost[ind]+f(ind-2,cost,dp);
    //     else return 0;
    //     return dp[ind] = min(left,right);
    // }
    int f(int ind,int n, vector<int>& cost,vector<int>& dp){
        if(ind>n) return 0; 
        if(dp[ind]!=-1) return dp[ind];
        int left = cost[ind]+f(ind+1,n,cost,dp);
        int right = INT_MAX;
        // if(ind<n)
        right = cost[ind]+f(ind+2,n,cost,dp);
        return dp[ind] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        int first = f(0,cost.size()-1,cost,dp);
        int second = f(1,cost.size()-1,cost,dp);
        return min(first,second);
    }
};